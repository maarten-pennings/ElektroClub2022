# Variant 2

The CD4060 is hard to obtain, the reset circuit is hard to get correct, 
the blinking patterns are not very random. Why not replace the CD4060 with an ATtiny85.


## Firmware

I wrote the [multiblink](multiblink) firmware.
It is tested on Nano and ATtiny85.

I used a [Nano to flash](https://makersportal.com/blog/2018/5/19/attiny85-arduino-board-how-to-flash-the-arduino-bootloader-and-run-a-simple-sketch) the ATtiny85.


## Schematics

The ATtiny85 has 8 pins, 2 are for power, one is for reset, so 5 left.
We have 5 groups of LEDs, so they can be hooked to those 5 GPIO pins.

However, we wanted a switch to control the speed or blinking pattern.
The first idea was to use the RESET pin for that. 
But once the RESET pin is reprogrammed, it is hard to reflash the ATtiny85.

Instead we opted for time multiplexing, the output pins, using them also for input.

See the [schematics](Schematic_ElektroClub2022tiny.pdf).


## Breadboard

The ATtiny85 with firmware, group drivers and switches is tested on a breadboard.
Here is demo [video](https://www.youtube.com/watch?v=RSclDXem_cg).


(end)

