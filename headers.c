#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* HORAS, VOOS, MINUTOS, partida, chegada, duracao,  */

/* Numero maximo de aeroportos suportados */
#define MAXAEROPORTS 40
/* Numero maximo de voos */
#define MAXVOOS 30000
/* Numero de caracteres maximo de um pais */
#define MAXCONTRY 30
/* Numero de caracteres maximo de um cidade */
#define MAXCITY 50

#define LEN_ID_AEROPORT 4

#define LEN_ID_VOO 7

typedef struct
{
    int hora;
    int minuto;
} Time;

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char id[LEN_ID_AEROPORT];
    char contry[MAXCONTRY];
    char city[MAXCITY];
} Aeroport;

typedef struct
{
    char id[LEN_ID_VOO];
    Aeroport airport_partida;
    Aeroport airport_chegada;
    Date date_partida;
    Time hora_partida;
    Time duracao;
    int max_passageiros;
} Voo;

Aeroport airports[MAXAEROPORTS];
int numAerports = 0;

char current_char = ' ';