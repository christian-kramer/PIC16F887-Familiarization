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
    ANSELH  = 0x2F;
    TRISA   = 0x01;
    TRISB   = 0x01;
    TRISD   = 0x00;
    ADCON0  = 0x01;
    ADCON1  = 0x0E;
    
    
    TMR0    = 0;
    T0CS    = 0;
    T0SE    = 0;
    PSA     = 0;
    PS0     = 1;
    PS1     = 1;
    PS2     = 1;
    
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
            if (count&0x10 && count&0x08 && count&0x04 && count&0x02 && count&0x01)
            {
                PORTD   = 0x01;
            }
            else
            {
                PORTD   = 0x00;
            }
        }
    }
    
    
    return (EXIT_SUCCESS);
}

