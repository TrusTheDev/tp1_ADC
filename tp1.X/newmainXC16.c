/*
 * File:   newmainXC16.c
 * Author: trusty
 *
 * Created on March 19, 2026, 5:31 PM
 */
#include <p33FJ256GP710.h>

int a, b, var_temp;

typedef union {
    struct {
        unsigned int C:1;
        unsigned int Z:1;
        unsigned int OV:1;
        unsigned int N:1;
        unsigned int RA:1;
        //IPL = orden de prioridades
        unsigned int IPL:3;
        unsigned int DC:1;
        unsigned int DA:1;
        unsigned int SAB:1;
        unsigned int OAB:1;
        unsigned int SB:1;
        unsigned int SA:1;
        unsigned int OB:1;
        unsigned int OA:1;
    } bits;
    struct {
        unsigned int :5;
        unsigned int IPL1:1;
        unsigned int IPL2:1;
        unsigned int IPL3:1;
    }IPLbits;
    unsigned int completo;
} t_sr;
t_sr status_register;

TRISD = 0x000A;

void espera(int valor1, int valor2)
{
    int i,j,k;

    for(i = 0; i < valor1; ++i)
    {
        j = i;
    }

    for(i = 0; i < valor2; ++i)
    {
        k = i;
    }
}

int main(void) {

    AD1PCFGH = 0xFFFF;
    AD1PCFGL = 0xFFFF;
    AD2PCFGL = 0xFFFF;

    int x, y;

    a = 10;
    b = 3;
    a -= b;
    status_register.completo = SR;
    var_temp = status_register.bits.C;
    var_temp = status_register.bits.IPL;
    a = status_register.IPLbits.IPL2;
    x = 200;
    y = 300;
    espera(x, y);
    x = 0;
    y = 3;
    espera(100, 400);
    b -= b;
    status_register.completo = SR;
    var_temp = status_register.bits.Z;
    var_temp = status_register.bits.N;

    while(1)
    {
        if(x < y)
            x = x + 1;
        else
            x = x - 1;
    }

}
