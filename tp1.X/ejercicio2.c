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

    struct {
        unsigned int puerta1 : 1;
        unsigned int puerta2 : 1;
        unsigned int puerta3 : 1;
        unsigned int puerta4 : 1;
        unsigned int puerta5 : 1;
        unsigned int presionGas : 1;
        unsigned int electricidad : 1;
        //Puede ignorarse
        unsigned int : 9;
    };
    unsigned int estados;
} sensor_t;



typedef union {
    struct {
        unsigned int motor : 1;
        unsigned int valvula : 1;
        unsigned int : 14;
    };
    unsigned int salida;
} salidas_t;

typedef union {
    struct {
        unsigned int temperatura_actual: 16;
    };
    unsigned int temperatura;
} termostato_t;

int NumPuertasCerradas(int pin) {
    int aux;
    aux = pin & 0x1F; // enmascaro los últimos 5 bits
    // aux = pin; (OJO, todos los pines del puerto B en entradas.)
    int cont = 0;
    // Cuento los bits en 1
    for (int i = 0; i < 5; i++) {
        if (aux & (1 << i)) {
            cont++;
        }
    }
    return cont;
}

sensor_t sensores;
salidas_t salidas;
salidas_t anterior;
termostato_t termostato;

#define UMBRAL 0x70A3 // 24º

void configuraciones() {
    //Puerto A como entrada (termostato variable)
    TRISA = 0xFFFF;
    //Puerto B como entrada (Sistema de control)
    TRISB = 0xFFFF;
    //Puerto C como salidas (motor y válvula de gas);
    TRISC = 0x0000;
    anterior.salida = 0;
}

void LogicaPrograma() {
    if (termostato.temperatura_actual < UMBRAL && sensores.presionGas && sensores.electricidad
            && NumPuertasCerradas(sensores.estados) >= 3) {
        salidas.motor = 1;
        salidas.valvula = 1;
    } else {
        salidas.motor = 0;
        salidas.valvula = 0;
    }
}

void EscribirSalidas() {
    if (salidas.salida != anterior.salida) {
        LATC = salidas.salida;
        anterior.salida = salidas.salida;
    }
}

void Ejercicio2() {
    configuraciones();
    while (1) {
        sensores.estados = PORTB;
        termostato.temperatura = PORTA;
        LogicaPrograma();
        // Comparo con el estado del pin anterior
        EscribirSalidas();
    }
}

