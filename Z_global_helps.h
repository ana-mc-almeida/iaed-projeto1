/*
 * File:
 * Author:
 * Description: funcoes auxiliares do projeto
 */
#ifndef HELPS
#define HELPS

#include "headers.h"

void print_airports()
{
    int i = 0;
    printf("\n**************************\n");
    for (i = 0; i < numAirports; i++)
    {
        Airport a;
        a = currente_airports[i];
        printf("%s - %s - %s\n", a.id, a.country, a.city);
    }
    printf("\n**************************\n");
}

#endif