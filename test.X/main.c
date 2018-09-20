/* 
 * File:   main.c
 * Author: Christian Kramer
 *
 * Created on September 3, 2018, 5:28 AM
 */

// #define _XTAL_FREQ 8000000
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#pragma config FOSC=INTRC_NOCLKOUT, WDTE=OFF, MCLRE=OFF, LVP=OFF     


/*
 * 
 */

char getLightValue()
{
    ADCON0bits.GO = 1;
    return ~ADRESH;
}


void main() {

    //ANSEL   = 0;
    //WPUB    = 0x00;
    ////ANSELH  = 0x3D;     // Analog/Digital, --101111
    ////TRISB   = 0xF7;     // I/O
    ////TRISD   = 0x00;     // I/O
    ////ADCON0  = 0x25;     // clock select, channel select, go, on
    //ADCON1  = 0x00;   // right or left justified, negative and positive reference voltages
    
    /*
    TMR0    = 0;        // instantiate timer at 0
    T0CS    = 0;        // select either internal or external source
    T0SE    = 0;        // XOR bit for T0CKI pin
    PSA     = 0;        // watchdog timer or previous selection
    PS0     = 1;        // selection for prescaler
    PS1     = 1;        // selection for prescaler
    PS2     = 1;        // selection for prescaler
    */
    
    TRISA   = 0x02; //00000100
    TRISD	= 0x00;
    ADCON0  = 0x05;
    
    char startValue = getLightValue();
    char count = 0;
    
    while (1) {
        char currentValue = getLightValue();
        if (currentValue > startValue + 5 && count < 100)
        {
            count++;
        }
        if (currentValue < startValue - 5 && count > 0)
        {
            count--;
        }
        if (count == 100)
        {
            PORTD = 0xFF;
        }
        if (count == 0)
        {
            PORTD = 0x01;
        }
    }
}

