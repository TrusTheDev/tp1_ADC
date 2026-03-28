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

/* Stimulus:
 * RD6 = Pulsador de encendido
 * RD7 = Pulsador de apagado
 * RD13 = condicion de seguridad
 */
typedef union {
    struct{
        unsigned int LED0VERDE: 1;
        unsigned int LED1ROJO: 1;
        unsigned int : 14;
    };
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
    // TRISD controles como entrada
    TRISD = 0X20C0;
    //La maquina empieza detenida (led rojo)
    LATAbits.LATA1 = 1;
    //El led verde deberia estar en 0 por default, pero me aseguro
    LATAbits.LATA0 = 0;
    
    while(1){
        controles.Controles = PORTD;
        leds.Leds = PORTA;
        if(controles.PS13SEG && !controles.PS7OFF){
            //Apago el led rojo
            LATAbits.LATA1 = 0;
            //Prendo el led verde
            LATAbits.LATA0 = 1;
            //Realiza el trabajo trabajoso de manera muy trabajadora
        }    
        // Si la maquina esta prendida pero la condicion de seguridad no se cumple 
        //y no esta activada la detencion
        if(controles.PS6ON && !controles.PS13SEG && !controles.PS7OFF){
            //Apago el led verde
            LATAbits.LATA0 = 0;
            //Prendo el led rojo
            LATAbits.LATA1 = 1;
            //Aviso de que no se cumple con la condicion de seguridad.
        }
        if(controles.PS7OFF){
            LATAbits.LATA0 = 0;
            LATAbits.LATA1 = 1;
            //Detencion subita del programa 
            return 0;
        }
    }   
}