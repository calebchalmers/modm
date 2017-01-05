/*
 * Copyright (c) 2016, Sascha Schade
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#include <modm/debug/logger.hpp>
#include <modm/architecture/architecture.hpp>

#include <modm/architecture/interface/can.hpp>
#include <modm/architecture/platform/driver/can/canusb/canusb.hpp>
#include <modm/architecture/platform/driver/can/socketcan/socketcan.hpp>

#include <modm/communication/communication.hpp>
#include <modm/communication/modm/backend/can.hpp>

#include <modm/communication/modm/backend/can/connector.hpp>
#include <modm/communication/modm/backend/zeromq/connector.hpp>

/**
 * Listens to a CAN bus connected by a CAN2USB and publishes modm messages with zeromq.
 *
 * How to use:
 * - Connect a CAN2USB to a CAN bus with traffic.
 * - Connect this CAN2USB by USB to your computer.
 * - Make sure the user can access the /dev/ttyUSB0 device.
 *   Brute force method is: #sudo chmod 777 /dev/ttyUSB0
 *   A wiser method is to add the user the appropriate group
 * - Adjust the baud rate of the CAN bus in this example.
 * - Do
 *   scons run
 * - All modm messages will be published on port 8211 by zeromq
 */

// Default baud rate
static constexpr uint32_t canBusBaudRate = 125000;

/* Either use an USB CAN2USB adaptor with modm Lawicel interpreter
   or use a CAN controller supported by Linux' SocketCAN.

   With SocketCAN the baudrate must be set with the operating system.
   $ ip link set can0 type can bitrate
*/
// static modm::hosted::CanUsb canUsb;
static modm::hosted::SocketCan canSocket;

// static modm::CanConnector< modm::hosted::CanUsb > canConnector(&canUsb);
static modm::CanConnector< modm::hosted::SocketCan > canConnector(&canSocket);

#undef MODM_LOG_LEVEL
#define	MODM_LOG_LEVEL modm::log::DEBUG

int
main()
{
	MODM_LOG_DEBUG << "ZeroMQ SocketCAN MODM bridge" << modm::endl;

	// if (not canUsb.open("/dev/ttyUSB0", canBusBaudRate)) {
	if (not canSocket.open("can0" /*, canBusBaudRate */)) {
		MODM_LOG_ERROR << "Could not open port" << modm::endl;
		exit(EXIT_FAILURE);
	}

	const std::string endpointOut = "tcp://*:8211";
	const std::string endpointIn  = "tcp://*:8212";

	modm::ZeroMQConnector zmqConnector(endpointIn, endpointOut, modm::ZeroMQConnector::Mode::PubPull);

	MODM_LOG_DEBUG << "Entering main loop" << modm::endl;

	while(true)
	{
		canConnector.update();
		zmqConnector.update();

		while (canConnector.isPacketAvailable())
		{
			modm::Header header = canConnector.getPacketHeader();
			modm::SmartPointer payload = canConnector.getPacketPayload();

			MODM_LOG_DEBUG << "C->Z " << header << " " << payload.getSize() << " " << payload << modm::endl;

			zmqConnector.sendPacket(header, payload);

			canConnector.dropPacket();
		}

		while (zmqConnector.isPacketAvailable())
		{
			modm::Header header = zmqConnector.getPacketHeader();
			modm::SmartPointer payload = zmqConnector.getPacketPayload();

			MODM_LOG_DEBUG << "Z->C " << header << " " << payload.getSize() << " " << payload << modm::endl;

			canConnector.sendPacket(header, payload);

			zmqConnector.dropPacket();
		}

		modm::delayMilliseconds(10);
	}

	// canUsb.close();
	canSocket.close();
}
