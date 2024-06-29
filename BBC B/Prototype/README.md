# BBC Model B/B+ Prototype Board v1.1

![Image of prototype v1.1 board in green](https://github.com/Board-Folk/keys/blob/main/BBC%20B/images/bbcb_prototype_v1_1_small.png)

A PS/2 and USB keyboard interface for the BBC Model B/B+ based on C64keyboard by Robert VanHazinga using an Arduino type board and an MT8816 switch chip. This is the original throughhole board. 
This is easier to build than the surface mount version. It currently won't work with the original BBC keyboard connected. 
The PS/2 configuration is for Arduino Nano, the USB, Seeeduino XIAO, same as the original project.
The XIAO does take a few seconds to boot and recognise the keyboard, it's not as quick as the Atmega version.
For Nano, you may need to toggle Arduino IDE between processor ATmega328P and ATmega328P (old bootloader) depending on which Nano you have.

* BOM

iBOM for the board.

* Gerber

Gerbers and gerber zip file for production.

* Kicad

Kicad project for the board.
