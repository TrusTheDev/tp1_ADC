/*
 * File:   ejercicio2.c
 * Author: trusty
 *
 * Created on March 23, 2026, 6:54 PM
 */


#include "xc.h"
#include "ejercicio2.h"
#include <p33FJ256GP710.h>

typedef union {
    struct{
        unsigned int puerta1: 1;
        unsigned int puerta2: 1;
        unsigned int puerta3: 1;
        unsigned int puerta4: 1;
        unsigned int puerta5: 1;
        unsigned int presionGas: 1;
        unsigned int electricidad: 1;
        //Puede ignorarse
        unsigned int : 9;
    };
    unsigned int estados;
} sensor_t;

void Ejercicio2() {    
    //Configuraciones de termostato
    //80 grados
    TRISA = 0x0000;
    LATA = 0xFFFF;
    int minimo = -20;
    
    // umbral
    int umbral = 24;
    
    //temperatura actual del sensor
    int temperatura;
    
    //Puerto B sensores de las puertas, gas y seguridad 
    PORTB = 0x0000; 

    //Configuración de pines
    //Levanto las 3 primeras puertas ON 
    TRISB = 0x0007;
    
    sensor_t sensores;
    
    sensores.estados = PORTB;
    int aux = PORTA;
    while(1){
        
        if(PORTB != sensores.estados){
            sensores.estados = PORTB;
        }
        
        if(aux != PORTA){
            aux = PORTA;
            temperatura = (aux*100) / 65535 + minimo;
        }
        
        while(sensores.electricidad){
            if(sensores.presionGas && temperatura < umbral) {
                //prendo el aire
            }
        }
    }
}
