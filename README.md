# PIC16F887-Familiarization
Quick project to learn analog and digital I/O on the PIC16F887 microcontroller

---

This program displays the truncated big endian 8-bit value of the potentiometer when the button is pushed. Schematics [here](http://ww1.microchip.com/downloads/en/DeviceDoc/40001296C.pdf).

I picked up a PICkit 2 for free the other day, and wanted to figure out how to use it. After some fiddling, I managed to successfully incorporate a digital input, a built-in analog-to-digital converter, and an output, all in one program. Interfacing directly with registers was a new experience for me, but I'm getting the hang of it.

---

## Blink

The PIC16F887 is packed incredibly full of features, and I've only begun to scratch the surface of what it can do. I set my sights on learning how to use the hardware timers next.

The program as it stood was pretty boring for the "off" state; all of the LEDs just stay off until you press the button. I wanted to indicate that it was waiting for user input with a blinking light to make things more interesting. I had played around with using the native XC8 "__delay_ms()" function to control the blinking, but that introduced lag when the button was pushed. I thought that offloading the timing onto an onboard timer would allow for blinking to occur without disturbing the program flow, and introducing unnecessary lag. After some tinkering, a 1/8 pulse is now generated every 2 seconds, and the switch between "off" and displaying the potentiometer value is instantaneous. I will attempt to make use of more hardware features in the future.