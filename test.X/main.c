/* 
 * File:   main.c
 * Author: Christian Kramer
 *
 * Created on September 3, 2018, 5:28 AM
 */

//#define _XTAL_FREQ 20000000
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#pragma config FOSC=INTRC_NOCLKOUT, WDTE=OFF, MCLRE=ON, LVP=OFF     


/*
 * 
 */
int main(int argc, char** argv) {

    //ANSEL   = 0;
    ANSELH  = 0x04;
    TRISA   = 0x01;
    TRISB   = 0x01;
    TRISD	= 0x00;
    ADCON0  = 0x01;
    ADCON1  = 0x0E;
    
    while (1) {
        if (~PORTB&1)
        {
            ADCON0bits.GO = 1;
            
            PORTD = ADRESH;
        }
        else
        {
            PORTD = 0x00;
        }
    }
    
    
    return (EXIT_SUCCESS);
}

