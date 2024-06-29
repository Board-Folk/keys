/*
  BBCUSB_keyboard - BBC B USB Keyboard library
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
#include <KeyboardController.h>

// Initialize USB Controller
USBHost usb;

// Attach keyboard controller to USB
KeyboardController keyboard(usb);


BBCUSBkeyboard ckey;
static volatile uint8_t kc,mod,modbuff;
static const BBCUSBKeymap_t *keymap = NULL;
static volatile bool kpress=false, currkeymap=false, capslock=false, bbcbreak=false;

// This function intercepts key press
void keyPressed() {
  kc = keyboard.getOemKey();
  mod = keyboard.getModifiers();
  kpress = true;
  BBCUSBkey();
}

// This function intercepts key release
void keyReleased() {
  kc = keyboard.getOemKey();
  mod = keyboard.getModifiers();
  kpress = false;
  BBCUSBkey();
}


void setup() {
  ckey.begin();
  if (debug) {
    Serial1.begin( 9600 );
    digitalWrite(ANALOG_SW_DATA, LOW);
    digitalWrite(ANALOG_SW_STROBE, LOW);
    digitalWrite(ANALOG_SW_RESET, LOW);
    digitalWrite(ANALOG_SW_ARRAY_START, LOW);
    digitalWrite(ANALOG_SW_ARRAY_END, LOW);
    digitalWrite(ANALOG_SW_AX3, LOW);
  }
   delay(200);
}

void loop() {
  // Process USB tasks
  usb.Task();
}

 
