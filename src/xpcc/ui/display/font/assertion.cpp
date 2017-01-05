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
		FLASH_STORAGE(uint8_t Assertion[]) =
		{
			0x18, 0x05, // total size of this array
			7,	// width (may vary)
			15,	// height
			0,	// hspace
			1, 	// vspace
			32,	// first char
			96,	// char count
			
			// char widths
			// for each character the separate width in pixels
			 7,  2,  5, 10,  7, 10,  8,  2,  4,  4, 
			 8,  6,  3,  5,  2,  6,  7,  4,  7,  7, 
			 7,  7,  7,  6,  7,  7,  2,  3,  5,  5, 
			 5,  7, 11,  7,  7,  7,  7,  7,  7,  7, 
			 7,  2,  7,  7,  6, 10,  7,  7,  7,  7, 
			 7,  7,  6,  7,  7, 12,  7,  6,  7,  4, 
			 6,  4,  7,  7,  3,  7,  7,  7,  7,  7, 
			 5,  7,  7,  2,  4,  7,  2, 10,  7,  7, 
			 7,  7,  6,  7,  5,  7,  7, 12,  7,  7, 
			 5,  5,  2,  5,  5,  7, 
			
			// font data
			// bit field of all characters
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 32
			0xFF, 0xFF, 0x0D, 0x0D, // 33
			0x07, 0x07, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, // 34
			0x10, 0x10, 0xFE, 0xFE, 0x10, 0x10, 0xFE, 0xFE, 0x10, 0x10, 0x01, 0x01, 0x0F, 0x0F, 0x01, 0x01, 0x0F, 0x0F, 0x01, 0x01, // 35
			0x78, 0xFC, 0x84, 0x87, 0x84, 0xBC, 0x38, 0x0E, 0x1E, 0x10, 0x70, 0x10, 0x1F, 0x0F, // 36
			0x1C, 0x3E, 0x22, 0xBE, 0xDC, 0x60, 0xB0, 0x98, 0x8C, 0x06, 0x0C, 0x06, 0x03, 0x01, 0x00, 0x07, 0x0F, 0x08, 0x0F, 0x07, // 37
			0xDE, 0xFF, 0x01, 0x21, 0x21, 0xEF, 0xEE, 0x20, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00, // 38
			0x07, 0x07, 0x00, 0x00, // 39
			0xF8, 0xFC, 0x02, 0x01, 0x01, 0x03, 0x04, 0x08, // 40
			0x01, 0x02, 0xFC, 0xF8, 0x08, 0x04, 0x03, 0x01, // 41
			0x88, 0xD8, 0x70, 0xFC, 0xFC, 0x70, 0xD8, 0x88, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, // 42
			0x40, 0x40, 0xF8, 0xF8, 0x40, 0x40, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, // 43
			0x00, 0x00, 0x00, 0x40, 0x78, 0x38, // 44
			0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, // 45
			0x00, 0x00, 0x38, 0x38, // 46
			0x00, 0x00, 0xE0, 0x7C, 0x0F, 0x01, 0x18, 0x1F, 0x03, 0x00, 0x00, 0x00, // 47
			0xFE, 0xFF, 0x01, 0x01, 0x01, 0xFF, 0xFE, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 48
			0x01, 0x01, 0xFF, 0xFF, 0x00, 0x00, 0x0F, 0x0F, // 49
			0x8E, 0xCF, 0x41, 0x41, 0x41, 0x7F, 0x3E, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08, // 50
			0x0E, 0x0F, 0x21, 0x21, 0x21, 0xFF, 0xDE, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 51
			0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x01, 0x01, 0x01, 0x01, 0x0F, 0x0F, 0x01, // 52
			0x9F, 0x9F, 0x11, 0x11, 0x11, 0xF1, 0xE1, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 53
			0xFE, 0xFF, 0x21, 0x21, 0x21, 0xEF, 0xCE, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 54
			0x01, 0x01, 0xE1, 0xF1, 0x3F, 0x1F, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, // 55
			0xDE, 0xFF, 0x21, 0x21, 0x21, 0xFF, 0xDE, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 56
			0x3E, 0x7F, 0x41, 0x41, 0x41, 0xFF, 0xFE, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 57
			0x70, 0x70, 0x07, 0x07, // 58
			0x00, 0x70, 0x70, 0x08, 0x0F, 0x07, // 59
			0x40, 0xE0, 0xB0, 0x18, 0x08, 0x00, 0x00, 0x01, 0x03, 0x02, // 60
			0x90, 0x90, 0x90, 0x90, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, // 61
			0x08, 0x18, 0xB0, 0xE0, 0x40, 0x02, 0x03, 0x01, 0x00, 0x00, // 62
			0x0E, 0x0F, 0x01, 0xC1, 0xE1, 0x3F, 0x1E, 0x00, 0x00, 0x00, 0x0D, 0x0D, 0x00, 0x00, // 63
			0xF8, 0xFC, 0x02, 0xF9, 0xFD, 0x05, 0xFD, 0xF9, 0x02, 0xFC, 0xF8, 0x01, 0x03, 0x04, 0x09, 0x0B, 0x0A, 0x0B, 0x09, 0x0A, 0x0B, 0x01, // 64
			0xFE, 0xFF, 0x41, 0x41, 0x41, 0xFF, 0xFE, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, // 65
			0xFF, 0xFF, 0x21, 0x21, 0x21, 0xFF, 0xDE, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 66
			0xFE, 0xFF, 0x01, 0x01, 0x01, 0x9F, 0x9E, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 67
			0xFF, 0xFF, 0x01, 0x01, 0x01, 0xFF, 0xFE, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 68
			0xFF, 0xFF, 0x21, 0x21, 0x21, 0x21, 0x01, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08, // 69
			0xFF, 0xFF, 0x21, 0x21, 0x21, 0x21, 0x01, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, // 70
			0xFE, 0xFF, 0x01, 0x41, 0x41, 0xDF, 0xDE, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 71
			0xFF, 0xFF, 0x20, 0x20, 0x20, 0xFF, 0xFF, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, // 72
			0xFF, 0xFF, 0x0F, 0x0F, // 73
			0x80, 0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 74
			0xFF, 0xFF, 0x20, 0x20, 0x70, 0xDF, 0x8F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, // 75
			0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x08, // 76
			0xFF, 0xFF, 0x01, 0x01, 0xFF, 0xFF, 0x01, 0x01, 0xFF, 0xFE, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, // 77
			0xFF, 0xFF, 0x01, 0x01, 0x01, 0xFF, 0xFE, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, // 78
			0xFE, 0xFF, 0x01, 0x01, 0x01, 0xFF, 0xFE, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 79
			0xFF, 0xFF, 0x41, 0x41, 0x41, 0x7F, 0x3E, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, // 80
			0xFE, 0xFF, 0x01, 0x01, 0x01, 0xFF, 0xFE, 0x07, 0x0F, 0x08, 0x08, 0x18, 0x3F, 0x27, // 81
			0xFF, 0xFF, 0x21, 0x21, 0x21, 0xFF, 0xDE, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, // 82
			0x9E, 0xBF, 0x21, 0x21, 0x21, 0xEF, 0xCE, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 83
			0x01, 0x01, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, // 84
			0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 85
			0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x01, 0x03, 0x06, 0x0C, 0x06, 0x03, 0x01, // 86
			0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x01, 0x03, 0x06, 0x0C, 0x06, 0x03, 0x03, 0x06, 0x0C, 0x06, 0x03, 0x01, // 87
			0x1F, 0xBF, 0xE0, 0x40, 0xE0, 0xBF, 0x1F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, // 88
			0x3F, 0x7F, 0xC0, 0xC0, 0x7F, 0x3F, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, // 89
			0x81, 0xC1, 0x61, 0x31, 0x1F, 0x0F, 0x00, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08, // 90
			0xFF, 0xFF, 0x01, 0x01, 0x0F, 0x0F, 0x08, 0x08, // 91
			0x01, 0x0F, 0x7C, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1F, 0x18, // 92
			0x01, 0x01, 0xFF, 0xFF, 0x08, 0x08, 0x0F, 0x0F, // 93
			0x20, 0x38, 0x0E, 0x03, 0x0E, 0x38, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 95
			0x01, 0x02, 0x04, 0x00, 0x00, 0x00, // 96
			0xF0, 0xF8, 0x08, 0x08, 0x08, 0xF8, 0xF8, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x0F, // 97
			0xFF, 0xFF, 0x08, 0x08, 0x08, 0xF8, 0xF0, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 98
			0xF0, 0xF8, 0x08, 0x08, 0x08, 0x38, 0x30, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0E, 0x06, // 99
			0xF0, 0xF8, 0x08, 0x08, 0x08, 0xFF, 0xFF, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x0F, // 100
			0xF0, 0xF8, 0x48, 0x48, 0x48, 0x78, 0x70, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0E, 0x06, // 101
			0x08, 0xFE, 0xFF, 0x09, 0x09, 0x00, 0x0F, 0x0F, 0x00, 0x00, // 102
			0xF0, 0xF8, 0x08, 0x08, 0x08, 0xF8, 0xF8, 0x07, 0x4F, 0x48, 0x48, 0x48, 0x7F, 0x3F, // 103
			0xFF, 0xFF, 0x08, 0x08, 0x08, 0xF8, 0xF0, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, // 104
			0xFB, 0xFB, 0x0F, 0x0F, // 105
			0x00, 0x00, 0xFB, 0xFB, 0x40, 0x40, 0x7F, 0x3F, // 106
			0xFF, 0xFF, 0x40, 0x40, 0xE0, 0xB8, 0x18, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, // 107
			0xFF, 0xFF, 0x0F, 0x0F, // 108
			0xF8, 0xF8, 0x08, 0x08, 0xF8, 0xF8, 0x08, 0x08, 0xF8, 0xF0, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, // 109
			0xF8, 0xF8, 0x08, 0x08, 0x08, 0xF8, 0xF0, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, // 110
			0xF0, 0xF8, 0x08, 0x08, 0x08, 0xF8, 0xF0, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 111
			0xF8, 0xF8, 0x08, 0x08, 0x08, 0xF8, 0xF0, 0x7F, 0x7F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 112
			0xF0, 0xF8, 0x08, 0x08, 0x08, 0xF8, 0xF8, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x7F, 0x7F, // 113
			0xF8, 0xF8, 0x30, 0x10, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, // 114
			0x70, 0xF8, 0x88, 0x88, 0x88, 0xB8, 0x30, 0x06, 0x0E, 0x08, 0x08, 0x08, 0x0F, 0x07, // 115
			0x08, 0xFE, 0xFF, 0x08, 0x08, 0x00, 0x07, 0x0F, 0x08, 0x08, // 116
			0xF8, 0xF8, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, // 117
			0xF8, 0xF8, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x03, 0x07, 0x0C, 0x08, 0x0C, 0x07, 0x03, // 118
			0xF8, 0xF8, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x03, 0x07, 0x0C, 0x08, 0x0C, 0x07, 0x07, 0x0C, 0x08, 0x0C, 0x07, 0x03, // 119
			0x38, 0x78, 0xC0, 0x80, 0xC0, 0x78, 0x38, 0x0E, 0x0F, 0x01, 0x00, 0x01, 0x0F, 0x0E, // 120
			0xF8, 0xF8, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x07, 0x4F, 0x48, 0x48, 0x48, 0x7F, 0x3F, // 121
			0x08, 0x88, 0xC8, 0x78, 0x38, 0x0F, 0x0F, 0x08, 0x08, 0x08, // 122
			0x40, 0xFE, 0xBF, 0x01, 0x01, 0x00, 0x0F, 0x1F, 0x10, 0x10, // 123
			0xFF, 0xFF, 0x0F, 0x0F, // 124
			0x01, 0x01, 0xBF, 0xFE, 0x40, 0x10, 0x10, 0x1F, 0x0F, 0x00, // 125
			0xC0, 0x60, 0xE0, 0xC0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 127
		};
	}
}

