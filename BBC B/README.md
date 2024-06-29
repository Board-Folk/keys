# BBC Model B and B+ Keyboard Adapters

![Image of BBC USB slim version 1 board in green](https://github.com/Board-Folk/keys/blob/main/BBC%20B/images/bbcb_usb_slimv1_small.png)

** Work in progress **

Keyboard interfaces for the BBC Model B and B+ based on C64keyboard by Robert VanHazinga using an Arduino type board and an MT8816 switch chip.

## Notes

* The break key is 'Print Screen'.
* The XIAO does take a few seconds to boot and recognise the keyboard, it's not as quick as the Atmega version.
* Some improvements need to be made to the USB code to improve games that use Ctrl, Shift, Caps Lock etc, as these don't work in the same way in the USB libraries used.
* More to follow.

## Boards

* USB Slim

A USB Keyboard Adapter that fits within the BBC B. Does not work concurrently with the BBC in-build keyboard. Uses the Seeduino XAIO.

* Prototype

Original thoughhole prototype which can use either the Arduino Nano for PS/2 or Seeduino XIAO for USB.

## Code

* Arduino

Arduino code (in C) for the above boards for both PS/2 and USB, based on C64keyboard by Robert VanHazinga. Code is licensed as LGPL v2.1. Will load in Arduino IDE.