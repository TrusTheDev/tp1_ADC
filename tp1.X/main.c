/*
 * File:   newmainXC16.c
 * Author: trusty
 *
 * Created on March 19, 2026, 5:31 PM
 */
#include "ejercicio1.h"
#include "ejercicio2.h"

int main(void) {
    
    AD1PCFGH = 0xFFFF;
    AD1PCFGL = 0xFFFF;
    AD2PCFGL = 0xFFFF;
    
    //Ejercicio1();
    Ejercicio2();
}
