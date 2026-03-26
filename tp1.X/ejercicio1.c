/*
 * File:   Ejercicio1.c
 * Author: trusty
 *
 * Created on March 23, 2026, 6:25 PM
 */
#include "xc.h"
#include "ejercicio1.h"
// ----------------->>>EJERCICIO 1 <<<------------------------
//Pulsadores y controles.
typedef union {
    struct{
        unsigned :6;
        unsigned PS6ON:1;
        unsigned PS7OFF:1;
        unsigned :5;
        unsigned PS13SEG:1;
        unsigned :2;
    };
    unsigned Controles;
} controles_t;

//Leds
typedef union {
    struct{
        unsigned LED0VERDE: 1;
        unsigned LED1ROJO: 1;
        unsigned : 14;
    };
    unsigned Leds;
} leds_t;

void Ejercicio1(){
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
    
    //Inicializo structs
    controles_t controles;
    leds_t leds;
    
    while(1){
        controles.Controles = PORTD;
        leds.Leds = PORTA;
        if(controles.PS13SEG == 0 && controles.PS7OFF == 0){
            leds.LED0VERDE = 1;
            //Realiza el trabajo trabajoso de manera muy trabajadora
        }    
        if(controles.PS13SEG == 1){
            leds.LED0VERDE = 0;
            leds.LED1ROJO = 1;
            //Aviso de que no se cumple con la condición de seguridad.
        }
        if(controles.PS7OFF){
            leds.LED0VERDE = 0;
            leds.LED1ROJO = 1;
            //Detención subita del programa
            return 0;
        }
    }   
}