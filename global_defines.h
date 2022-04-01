/*
 * File: global_defines.h
 * Author: Ana Margarida Almeida - 102618
 * Description: Definição das constantes
 */

#ifndef CONSTANTS
#define CONSTANTS

/* Numero maximo de airportos suportados */
#define MAXAIRPORTS 40
/* Tamanho da string que contem o id de um aeroporto */
#define LEN_ID_AIRPORT 4
/* Numero de caracteres maximo de um pais */
#define MAXCOUNTRY 31
/* Numero de caracteres maximo de um cidade */
#define MAXCITY 51

/* Numero maximo de voos */
#define MAXFLIGHTS 30000
/* Tamanho da string que contem o id de um voo */
#define LEN_ID_FLIGHT 7
/* Numero de letras no id de um voo */
#define LETRAS_ID 2
/* Numero maximo de passageiros */
#define MAX_PASSAGERS 100
/* Numero minimo de passageiros */
#define MIN_PASSAGERS 10

/* Dia em que a data do sistema e inicializada */
#define INITIAL_DAY 1
/* Mes em que a data do sistema e inicializada */
#define INITIAL_MONTH 1
/* Ano em que a data do sistema e inicializada */
#define INITIAL_YEAR 2022

/* Numero maximo de digitos de um inteiro em c */
#define MAX_INT 11

/* Definicao do estado */
#define ARRIVING 1
#define DEPARTING 0

#endif
