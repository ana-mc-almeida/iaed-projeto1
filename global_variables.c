/*
 * File:
 * Author:
 * Description: Definição das constantes
 */

#ifndef VARIABLES
#define VARIABLES

#include "headers.c"

Airport airports[MAXAIRPORTS];
int numAirports = 0;

Flight flights[MAXFLIGHTS];
int numFlights = 0;

Date current_date = {DIA_INICIAL, MES_INICIAL, ANO_INICIAL};

char current_char = ' ';

#endif