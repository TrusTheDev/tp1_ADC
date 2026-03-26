/*
 * File:   Ejercicio1.c
 * Author: trusty
 *
 * Created on March 23, 2026, 6:25 PM
 */
#include "xc.h"
#include "ejercicio1.h"
#include <p33FJ256GP710.h>
// ----------------->>>EJERCICIO 1 <<<------------------------
//Pulsadores y controles.
typedef union {
    struct{
        unsigned int LED0VERDE: 1;
        unsigned int LED1ROJO: 1;
        unsigned int : 14;
    }bits;
    unsigned int Leds;
} leds_t;

typedef union {
    struct{
        unsigned int :6;
        unsigned int PS6ON:1;
        unsigned int PS7OFF:1;
        unsigned int :5;
        unsigned int PS13SEG:1;
        unsigned int :2;
    };
    unsigned Controles;
} controles_t;

//Leds
    leds_t leds;
    controles_t controles;

void Ejercicio1(){
    //Inicializo structs

    //configuracion de pines
    // TRISA leds
    TRISA = 0x0000;
    // TRISD controles
    TRISD = 0X20C0;
    
    TRISD = 0x0;
    
    //La maquina empieza detenida (led rojo)
    LATAbits.LATA1 = 1;
    //El led verde deberia estar en 0 por default, pero me aseguro
    LATAbits.LATA0 = 0;
    
    
    while(1){
        controles.Controles = PORTD;
        leds.bits.LED0VERDE = 1;
        if(controles.PS13SEG == 0 && controles.PS7OFF == 0){
            leds.bits.LED0VERDE = 1;
            //Realiza el trabajo trabajoso de manera muy trabajadora
        }    
        if(controles.PS13SEG == 1){
            leds.bits.LED0VERDE = 0;
            leds.bits.LED1ROJO = 1;
            //Aviso de que no se cumple con la condición de seguridad.
        }
        if(controles.PS7OFF){
            leds.bits.LED0VERDE = 0;
            leds.bits.LED1ROJO = 1;
            //Detención subita del programa
            return 0;
        }
    }   
}