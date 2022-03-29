/*
 * File:
 * Author:
 * Description: Definição das constantes
 */

#ifndef VARIABLES
#define VARIABLES

#include "headers.h"

char current_char = ' ';

Airport currente_airports[MAXAIRPORTS];
int numAirports = 0;

Flight currente_flights[MAXFLIGHTS];
int numFlights = 0;

Date current_date = {INITIAL_DAY, INITIAL_MONTH, INITIAL_YEAR};

/* Indicativo do numero de dias de cada mes */
int days_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

#endif
