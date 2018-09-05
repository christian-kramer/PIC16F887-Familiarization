/* 
 * File:   main.c
 * Author: Christian Kramer
 *
 * Created on September 3, 2018, 5:28 AM
 */

//#define _XTAL_FREQ 8000000
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#pragma config FOSC=INTRC_NOCLKOUT, WDTE=OFF, MCLRE=ON, LVP=OFF     


/*
 * 
 */
int main(int argc, char** argv) {

    //ANSEL   = 0;
    ANSELH  = 0x2F;     // Analog/Digital, --101111
    TRISA   = 0x01;     // I/O
    TRISB   = 0x01;     // I/O
    TRISD   = 0x00;     // I/O
    ADCON0  = 0x01;     // clock select, channel select, go, on
    //ADCON1  = 0x00;   // right or left justified, negative and positive reference voltages
    
    
    TMR0    = 0;        // instantiate timer at 0
    T0CS    = 0;        // select either internal or external source
    T0SE    = 0;        // XOR bit for T0CKI pin
    PSA     = 0;        // watchdog timer or previous selection
    PS0     = 1;        // selection for prescaler
    PS1     = 1;        // selection for prescaler
    PS2     = 1;        // selection for prescaler
    
    int count;
    
    while (1) {
        if (T0IF)
        {
            count++;
            T0IF = 0;
        }
        if (count == 256)
        {
            count = 0;
        }
        
        if (~PORTB&1)
        {
            ADCON0bits.GO = 1;
            
            PORTD = ADRESH;
        }
        else
        {
            if (count&0x1F)
            {
                PORTD   = 0x00;
            }
            else
            {
                PORTD   = 0x01;
            }
        }
    }
    
    
    return (EXIT_SUCCESS);
}

