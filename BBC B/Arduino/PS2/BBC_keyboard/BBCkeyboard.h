/*
  BBCkeyboard - BBC B Keyboard Library
  Adapted by Ian Cudlip

  Based on C64keyboard - Commodore Keyboard library by Hartland PC LLC
  Copyright (c) 2022 Hartland PC LLC
  Written by Robert VanHazinga

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef BBCkeyboard_h
#define BBCkeyboard_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#define BBC_KEYMAP_SIZE 	   152 // Size of each array in the key maps

#include "keymapping.h"

#define debug   false    // Set true for serial monitor of BBC keycodes and PS/2 keycodes

#define MT8808  false    // This has to be set to false now as we use more lines than the MT8808 provides

//PS2 communication pins
#define DATA_PIN				12 // Data pin for PS2 keyboard
#define IRQ_PIN					3  // Interrupt pin for PS2 keyboard

//Scan code value to enable a key map. Default is key map 1.
#define KEY_MAP_1				0x6B // F11?
#define KEY_MAP_2				0x6C // F12?

//Key map value to ignore key press
#define IGNORE_KEYCODE			0xAA //(DEC 170) (Must be > 128)

// Key map value to reset the MT88xx chip
#define MT_RESET        0x6C // (DEC 108) F12 activates MT88XX reset

//MT88xx control pins
#define ANALOG_SW_DATA      2 // Sets selected cross switch on/off (Old 13)
#define ANALOG_SW_STROBE    4 // Strobe timing pulse
#define ANALOG_SW_RESET     13 // Reset all MT88XX cross switches to off (Old 2)
#define ANALOG_SW_ARRAY_START 5 // First pin of 6 bit switch addressing. AY2-0 & AX2-0
#define ANALOG_SW_ARRAY_END   10 // Last pin of 6 bit switch addressing. AY2-0 & AX2-0
#define ANALOG_SW_AX3     11 // Pin that controls AX3 (MT8812 & MT8816) 

//BBC Break Key
#define BBCBREAK_PIN     A0

// Key map value for capslock
#define CAPSLOCK_KEY    0x03 // CapsLock key 

#define BBCLSHFT  0
#define BBCRSHFT  0

#define BBCBREAK  4

class BBCkeyboard {
  public:
    BBCkeyboard();
    
    static void begin(const BBCKeymap_t &map = BBCKeymap_main);
};
#endif
