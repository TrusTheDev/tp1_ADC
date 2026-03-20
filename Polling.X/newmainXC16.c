/*
 * File:   newmainXC16.c
 * Author: trusty
 *
 * Created on March 20, 2026, 9:20 AM
 */


#include <xc.h>

int main(void)
{
    
    
    // Todos digitales
    AD1PCFGH = 0xFFFF;
    AD1PCFGL = 0xFFFF;
    AD2PCFGL = 0xFFFF;

    // Configuración de pines
    TRISBbits.TRISB0 = 0; // LED como salida
    TRISBbits.TRISB1 = 1; // Pulsador como entrada

    LATBbits.LATB0 = 0;   // LED apagado

    while(1)
    {       
        if(PORTBbits.RB1 == 1) // botón presionado
        {
            LATBbits.LATB0 = 1; // prender LED
        }
        else
        {
            LATBbits.LATB0 = 0; // apagar LED
        }
    }

    return 0;
}