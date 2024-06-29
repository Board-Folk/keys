# Acorn Electron Keyboard Adapters

![Image of PS2 slim version 1 board in green](https://github.com/Board-Folk/keys/blob/main/Acorn%20Electron/images/electron_ps2_slim_v1_small.png)

More information to follow. A keyboard interface for the Acorn Electron based on C64keyboard by Robert VanHazinga using an Arduino type board and an MT8816 switch chip.

## Notes

* The break key is 'Print Screen'.
* More to follow

## Boards

* PS/2 Slim

A PS/2 Keyboard Adapter that fits within the Acorn Electron to provide a PS/2 port at the position of the UHF output socket (with the modulator removed).

* Prototype

Original thoughhole prototype which can use either the Arduino Nano for PS/2 or Seeduino XIAO for USB. This won't fit inside with the lid on. Code for the XIAO not done yet.

## Code

* Arduino

Arduino code (in C) for the above boards as PS/2, based on C64keyboard by Robert VanHazinga. Code is licensed as LGPL v2.1. Will load in Arduino IDE.