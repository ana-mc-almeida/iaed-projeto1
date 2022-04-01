/*
 * File: global_variables.h
 * Author: Ana Margarida Almeida - 102618
 * Description: Definição das variveis globais
 */

#ifndef VARIABLES
#define VARIABLES

#include "headers.h"

/* ultimo caracter lido */
char current_char = ' ';

/* lista de aeroportos */
Airport currente_airports[MAXAIRPORTS];
/* numero de aeroportos no sistema */
int numAirports = 0;

/* lista de voos */
Flight currente_flights[MAXFLIGHTS];
/* numero de voos no sistema */
int numFlights = 0;

/* data do sistema */
Date current_date = {INITIAL_DAY, INITIAL_MONTH, INITIAL_YEAR};

/* Indicativo do numero de dias de cada mes */
int days_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

#endif
