/*
 * Copyright (c) 2010-2012, Fabian Greif
 * Copyright (c) 2012-2013, Niklas Hauser
 * Copyright (c) 2013, Kevin Laeufer
 * Copyright (c) 2013, 2015, Sascha Schade
 * Copyright (c) 2014, Daniel Krebs
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

// created with FontCreator 3.0

#include <modm/architecture/driver/accessor.hpp>

namespace modm
{
	namespace font
	{
		FLASH_STORAGE(uint8_t FixedWidth5x8[]) =
		{
			0x48, 0x02, // total size of this array
			5,	// width (may vary)
			8,	// height
			0,	// hspace
			1, 	// vspace
			32,	// first char
			96,	// char count
			
			// char widths
			// for each character the separate width in pixels
			 5,  5,  5,  5,  5,  5,  5,  5,  5,  5, 
			 5,  5,  5,  5,  5,  5,  5,  5,  5,  5, 
			 5,  5,  5,  5,  5,  5,  5,  5,  5,  5, 
			 5,  5,  5,  5,  5,  5,  5,  5,  5,  5, 
			 5,  5,  5,  5,  5,  5,  5,  5,  5,  5, 
			 5,  5,  5,  5,  5,  5,  5,  5,  5,  5, 
			 5,  5,  5,  5,  5,  5,  5,  5,  5,  5, 
			 5,  5,  5,  5,  5,  5,  5,  5,  5,  5, 
			 5,  5,  5,  5,  5,  5,  5,  5,  5,  5, 
			 5,  5,  5,  5,  5,  5, 
			
			// font data
			// bit field of all characters
			0x00, 0x00, 0x00, 0x00, 0x00, // 32
			0x00, 0x06, 0x5F, 0x06, 0x00, // 33
			0x07, 0x03, 0x00, 0x07, 0x03, // 34
			0x24, 0x7E, 0x24, 0x7E, 0x24, // 35
			0x24, 0x2A, 0x7F, 0x2A, 0x12, // 36
			0x23, 0x13, 0x08, 0x64, 0x62, // 37
			0x36, 0x49, 0x56, 0x20, 0x50, // 38
			0x00, 0x08, 0x07, 0x03, 0x00, // 39
			0x00, 0x00, 0x3E, 0x41, 0x00, // 40
			0x00, 0x41, 0x3E, 0x00, 0x00, // 41
			0x08, 0x3E, 0x1C, 0x3E, 0x08, // 42
			0x08, 0x08, 0x3E, 0x08, 0x08, // 43
			0x00, 0x80, 0x70, 0x30, 0x00, // 44
			0x08, 0x08, 0x08, 0x08, 0x08, // 45
			0x00, 0x00, 0x60, 0x60, 0x00, // 46
			0x20, 0x10, 0x08, 0x04, 0x02, // 47
			0x3E, 0x51, 0x49, 0x45, 0x3E, // 48
			0x00, 0x42, 0x7F, 0x40, 0x00, // 49
			0x62, 0x51, 0x49, 0x49, 0x46, // 50
			0x22, 0x49, 0x49, 0x49, 0x36, // 51
			0x18, 0x14, 0x12, 0x7F, 0x10, // 52
			0x2F, 0x49, 0x49, 0x49, 0x31, // 53
			0x3C, 0x4A, 0x49, 0x49, 0x30, // 54
			0x01, 0x71, 0x09, 0x05, 0x03, // 55
			0x36, 0x49, 0x49, 0x49, 0x36, // 56
			0x06, 0x49, 0x49, 0x29, 0x1E, // 57
			0x00, 0x00, 0x14, 0x00, 0x00, // 58
			0x00, 0x80, 0x64, 0x00, 0x00, // 59
			0x08, 0x14, 0x22, 0x41, 0x00, // 60
			0x14, 0x14, 0x14, 0x14, 0x14, // 61
			0x00, 0x41, 0x22, 0x14, 0x08, // 62
			0x02, 0x01, 0x59, 0x09, 0x06, // 63
			0x3E, 0x41, 0x5D, 0x55, 0x1E, // 64
			0x7E, 0x11, 0x11, 0x11, 0x7E, // 65
			0x7F, 0x49, 0x49, 0x49, 0x36, // 66
			0x3E, 0x41, 0x41, 0x41, 0x22, // 67
			0x7F, 0x41, 0x41, 0x41, 0x3E, // 68
			0x7F, 0x49, 0x49, 0x49, 0x41, // 69
			0x7F, 0x09, 0x09, 0x09, 0x01, // 70
			0x3E, 0x41, 0x49, 0x49, 0x7A, // 71
			0x7F, 0x08, 0x08, 0x08, 0x7F, // 72
			0x00, 0x41, 0x7F, 0x41, 0x00, // 73
			0x30, 0x40, 0x40, 0x40, 0x3F, // 74
			0x7F, 0x08, 0x14, 0x22, 0x41, // 75
			0x7F, 0x40, 0x40, 0x40, 0x40, // 76
			0x7F, 0x02, 0x04, 0x02, 0x7F, // 77
			0x7F, 0x02, 0x04, 0x08, 0x7F, // 78
			0x3E, 0x41, 0x41, 0x41, 0x3E, // 79
			0x7F, 0x09, 0x09, 0x09, 0x06, // 80
			0x3E, 0x41, 0x51, 0x21, 0x5E, // 81
			0x7F, 0x09, 0x09, 0x19, 0x66, // 82
			0x26, 0x49, 0x49, 0x49, 0x32, // 83
			0x01, 0x01, 0x7F, 0x01, 0x01, // 84
			0x3F, 0x40, 0x40, 0x40, 0x3F, // 85
			0x1F, 0x20, 0x40, 0x20, 0x1F, // 86
			0x3F, 0x40, 0x38, 0x40, 0x3F, // 87
			0x63, 0x14, 0x08, 0x14, 0x63, // 88
			0x07, 0x08, 0x70, 0x08, 0x07, // 89
			0x61, 0x51, 0x49, 0x45, 0x43, // 90
			0x00, 0x00, 0x7F, 0x41, 0x00, // 91
			0x02, 0x04, 0x08, 0x10, 0x20, // 92
			0x00, 0x41, 0x7F, 0x00, 0x00, // 93
			0x04, 0x02, 0x01, 0x02, 0x04, // 94
			0x80, 0x80, 0x80, 0x80, 0x80, // 95
			0x00, 0x03, 0x07, 0x00, 0x00, // 96
			0x20, 0x54, 0x54, 0x54, 0x78, // 97
			0x7F, 0x44, 0x44, 0x44, 0x38, // 98
			0x38, 0x44, 0x44, 0x44, 0x28, // 99
			0x38, 0x44, 0x44, 0x44, 0x7F, // 100
			0x38, 0x54, 0x54, 0x54, 0x08, // 101
			0x08, 0x7E, 0x09, 0x09, 0x00, // 102
			0x18, 0xA4, 0xA4, 0xA4, 0x7C, // 103
			0x7F, 0x08, 0x08, 0x70, 0x00, // 104
			0x00, 0x00, 0x7D, 0x40, 0x00, // 105
			0x40, 0x80, 0x84, 0x7D, 0x00, // 106
			0x7F, 0x10, 0x28, 0x44, 0x00, // 107
			0x00, 0x00, 0x7F, 0x40, 0x00, // 108
			0x7C, 0x04, 0x18, 0x04, 0x78, // 109
			0x7C, 0x04, 0x04, 0x78, 0x00, // 110
			0x38, 0x44, 0x44, 0x44, 0x38, // 111
			0xFC, 0x24, 0x24, 0x24, 0x18, // 112
			0x18, 0x24, 0x24, 0x24, 0xFC, // 113
			0x44, 0x78, 0x44, 0x04, 0x08, // 114
			0x08, 0x54, 0x54, 0x54, 0x20, // 115
			0x02, 0x3F, 0x42, 0x22, 0x00, // 116
			0x3C, 0x40, 0x40, 0x40, 0x3C, // 117
			0x1C, 0x20, 0x40, 0x20, 0x1C, // 118
			0x3C, 0x40, 0x30, 0x40, 0x3C, // 119
			0x6C, 0x10, 0x10, 0x6C, 0x00, // 120
			0x1C, 0xA0, 0xA0, 0xA0, 0x7C, // 121
			0x64, 0x54, 0x54, 0x4C, 0x00, // 122
			0x08, 0x3E, 0x41, 0x41, 0x00, // 123
			0x00, 0x00, 0x77, 0x00, 0x00, // 124
			0x00, 0x41, 0x41, 0x3E, 0x08, // 125
			0x10, 0x08, 0x10, 0x08, 0x00, // 126
			0x7C, 0x46, 0x43, 0x46, 0x7C, // 127
		};
	}
}

