# PIC16F887-Familiarization
Quick project to learn analog and digital I/O on the PIC16F887 microcontroller

---

This program displays the truncated big endian 8-bit value of the potentiometer when the button is pushed. Schematics [here](http://ww1.microchip.com/downloads/en/DeviceDoc/40001296C.pdf).

I picked up a PICkit 2 for free the other day, and wanted to figure out how to use it. After some fiddling, I managed to successfully incorporate a digital input, a built-in analog-to-digital converter, and an output, all in one program. Interfacing directly with registers was a new experience for me, but I'm getting the hang of it.

---

## Light Sensor Prototype

I've been working on getting my light sensor project ready for production, and part of that was choosing the PIC10F220 as the minimum microprocessor needed for the application. Unfortunately, in addition to minimal peripherals, it also has minimal Flash and SRAM... 375 bytes and 16 bytes, respectively. Fitting reliable decision-making for whether or not the photoresistor is detecting a shadow will be a challenge.

The system I devised is simple: the microcontroller would record the light level when it first boots up, and then compare the most recent level with that initial reading. Essentially, if the new level is higher than the old level, the "score" variable is incremented by 1. If the new level is lower than the old level, the "score" variable is decrementedf by 1. This repeats X times at which point the microcontroller decides it's "sure" that the photoresistor is, in fact, experiencing darkness/light and not just random noise... at which point it switches the array of LEDs connected to PORTD on or off accordingly. The number of times can be increased to increase the reliability of the program, at the cost of responsiveness. Future experimentation and modification is likely, but will take place on my prototype hardware as this works well on my PIC16F887 demo board.