/*
 * File:
 * Author:
 * Description: Definição das constantes
 */

#ifndef VARIABLES
#define VARIABLES

#include "headers.c"

Airport currente_airports[MAXAIRPORTS];
int numAirports = 0;

Flight currente_flights[MAXFLIGHTS];
int numFlights = 0;

Date current_date = {DIA_INICIAL, MES_INICIAL, ANO_INICIAL};

char current_char = ' ';

int days_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

#endif