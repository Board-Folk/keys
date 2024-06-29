/*
  BBCUSB_keyboard - BBC USB Keyboard library
  Adapted by Ian Cudlip
  v1 29/06/2024

  Based on C64keyboard - Commodore Keyboard library by Hartland PC LLC
  Copyright (c) 2022 Hartland PC LLC
  Written by Robert VanHazinga

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include "BBCUSBkeyboard.h"

void resetMT88(void) {
  digitalWrite(ANALOG_SW_DATA, LOW);
  digitalWrite(ANALOG_SW_RESET, HIGH);
  digitalWrite(ANALOG_SW_STROBE, HIGH);
  digitalWrite(ANALOG_SW_RESET, LOW);
  digitalWrite(ANALOG_SW_STROBE, LOW);
  digitalWrite(ANALOG_SW_DATA, HIGH);
  modbuff = 0;
  
  capslock = false;
  bbcbreak = false;
  kpress = false;
  currkeymap = false;
}

void setswitch(uint8_t c, bool kstate) {
  int bitr;
  bool state;
  
  // Too few pins on this to do.
  if (debug) {
    Serial1.print("Send to switch: ");
    Serial1.print(c,DEC);
    Serial1.print(" ");
    Serial1.print(kstate,BIN);
    Serial1.println("");
    return;
  }

  digitalWrite(ANALOG_SW_DATA, kstate);
  
  if ((c > 55 && c < 64) || (c > 23 && c < 32) || (c > 71 && c < 80)) {
    c -= 24;
    digitalWrite(ANALOG_SW_AX3, HIGH);
  } else {
    if (c > 63 && c < 72) {
      c -= 48;
      digitalWrite(ANALOG_SW_AX3, HIGH);
    }
  }

  if (c < 80) {
    for (int currentPin = ANALOG_SW_ARRAY_START; currentPin <= ANALOG_SW_ARRAY_END; ++currentPin) {
      bitr = (currentPin - ANALOG_SW_ARRAY_START);
      state = bitRead(c, bitr);
      digitalWrite(currentPin, state);
    }
    digitalWrite(ANALOG_SW_STROBE, HIGH);
    digitalWrite(ANALOG_SW_STROBE, LOW);
  }
  digitalWrite(ANALOG_SW_AX3, LOW);

  // Reset switch state pin to default high state.
  digitalWrite(ANALOG_SW_DATA, HIGH);

}

void debugkey(uint8_t c) {
  Serial1.print("BBCUSB Keycode: ");
  Serial1.print(c);
  Serial1.print("  (USB Code: ");
  Serial1.print(kc);
  Serial1.print(" Hex: ");
  Serial1.print(kc, HEX);
  Serial1.print(")");
  Serial1.print("  Modfier: ");
  for (int i = 7; i >= 0; i--) {
    bool b = bitRead(mod, i);
    Serial1.print(b);
  }
  Serial1.print("  Key Press: ");
  Serial1.println(kpress);
}

void BBCUSBkey() {

  uint8_t c = 0;

  //  debug output
  if (debug) {
    debugkey(c);
  }

  // MT reset function    
  if (kc == MT_RESET) {
    resetMT88();
    c = IGNORE_KEYCODE;
  }
  
  // Shift Key State
  setswitch(BBCSHIFT, (mod & 0x02) || (mod & 0x20));
  delay(1);

  // Ctrl Key State
  setswitch(BBCCTRL, (mod & 0x01) || (mod & 0x10));
  delay(1);

  // BBC Break Key
  if (kc == BBCBREAK) {
    if (!kpress) {
      bbcbreak = false;
      digitalWrite(BBCBREAK_PIN, LOW);
      if (debug) {
        Serial1.println("Break Off");
      }
    } else {
      bbcbreak = true;
      digitalWrite(BBCBREAK_PIN, HIGH);
      if (debug) {
        Serial1.println("Break On");
      }
    }
    c = IGNORE_KEYCODE;
  }

  // Capslock function - not yet
  if (kc == CAPSLOCK_KEY && kpress) {
    capslock = !capslock;

    if (debug) {
      if (capslock) { 
        Serial1.println("Caps Lock on");
      } else {
        Serial1.println("Caps Lock off");
      }
    }
    setswitch(BBCCAPS, HIGH);
    delay(100);
    setswitch(BBCCAPS, LOW);
    delay(100);
    c = IGNORE_KEYCODE;
  }

  // Keymap Handling
  if (kc == KEYMAP_KEY && kpress) {
    currkeymap = !currkeymap;
    c = IGNORE_KEYCODE;
  }

  // Key Process      
  if (currkeymap && c != IGNORE_KEYCODE) {
    if ((mod & 0x02) || (mod & 0x20)) {
      c = pgm_read_byte(keymap -> shift_2 + kc);
    } else {
      c = pgm_read_byte(keymap -> noshift_2 + kc);
    }
  }

  if (!currkeymap && c != IGNORE_KEYCODE) {
    if ((mod & 0x02) || (mod & 0x20)) {
      c = pgm_read_byte(keymap -> shift_1 + kc);
    } else {
      c = pgm_read_byte(keymap -> noshift_1 + kc);
    }
  }

  // Process normal keypress

  if (c != IGNORE_KEYCODE) {
    // Key
    setswitch(c, kpress);
  }
}

void BBCUSBkeyboard::begin(const BBCUSBKeymap_t & map) {

  keymap = & map;

  // initialize the pins

  for (int currentPin = ANALOG_SW_ARRAY_START; currentPin <= ANALOG_SW_ARRAY_END; ++currentPin) {
    pinMode(currentPin, OUTPUT);
  }

  pinMode(ANALOG_SW_AX3, OUTPUT);     // MT881x extra bit
  pinMode(ANALOG_SW_STROBE, OUTPUT);  // MT88XX strobe
  pinMode(ANALOG_SW_DATA, OUTPUT);    // MT88XX data
  pinMode(ANALOG_SW_RESET, OUTPUT);   // MT88XX reset
  pinMode(ANALOG_SW_DATA, OUTPUT);    // MT88XX data

  pinMode(BBCBREAK_PIN, OUTPUT);

  if (!debug) resetMT88();

}

BBCUSBkeyboard::BBCUSBkeyboard() {
  // nothing to do here, begin() does it all
}
