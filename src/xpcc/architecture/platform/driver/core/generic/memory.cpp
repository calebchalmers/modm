/*
 * Copyright (c) 2013-2014, 2016, Niklas Hauser
 * Copyright (c) 2013-2014, Kevin Laeufer
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#include <modm/architecture/detect.hpp>

#ifdef MODM_OS_HOSTED

#include <modm/architecture/interface/memory.hpp>
#include <stdlib.h>

void *
operator new(size_t size, modm::MemoryTraits)
{
	return ::operator new(size);
}

void *
operator new[](size_t size, modm::MemoryTraits)
{
	return ::operator new[](size);
}

#endif
