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
    char id[4];
    char contry[MAXCONTRY];
    char city[50];
} Aeroport;

typedef struct
{
    char id[7];
    Aeroport airport_partida;
    Aeroport airport_chegada;
    Date date_partida;
    Time hora_partida;
    Time duracao;
    int max_passageiros;
} Voo;

Aeroport airports[MAXAEROPORTS];
int numAerports = 0;

Date get_data()
{
    Date date;
    scanf("%d-%d-%d", &date.day, &date.month, &date.year);
    return date;
}

void get_IDAeroport(char s[])
{
    char c;
    int i = 0;
    while (!isspace(c = getchar()))
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
}

void get_pais(char s[])
{
    char c;
    int i = 0;
    while (!isspace(c = getchar()))
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
}

void get_city(char s[])
{
    char c;
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
}

int check_invalid_airportID(char s[])
{
    int flag = 1, i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (islower(s[i]))
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int check_duplicate_airport(char s[])
{
    int flag = 1, i;
    for (i = 0; i < numAerports; i++)
    {
        if (strcmp(airports[i].id, s))
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

void add_airport()
{
    char id[4];
    Aeroport airport;

    get_IDAeroport(id);
    if (!check_invalid_airportID(id))
        printf("invalid airports ID\n");
    else if (numAerports + 1 >= MAXAEROPORTS)
        printf("too many airports\n");
    else if (!check_duplicate_airport(id))
        printf("duplicate airport\n");
    else
    {
        strcpy(airport.id, id);
        get_pais(airport.contry);
        get_city(airport.city);
        airports[numAerports] = airport;
        numAerports++;

        printf("airport %s\n", airport.id);
    }
}

int main()
{
    char carater_atual = ' ';

    while (carater_atual != EOF)
    {
        /* obter carater indicativo da operacao */
        carater_atual = getchar();
        /* absorver o espaco que vem sempre a seguir */
        getchar();

        switch (carater_atual)
        {
        /* termina o programa */
        case 'q':
            return 0;
            break;

        /* adiciona um novo aeroporto ao sistema */
        case 'a':
            add_airport();
            break;

        /* lista os aeroportos */
        case 'l':
            /* code */
            break;

        /* adiciona um novo voo ou lista todos os voos */
        case 'v':
            /* code */
            break;

        /* lista os voos com partida de um aeroporto */
        case 'p':
            /* code */
            break;

        /* lista os voos com chegada a um aeroporto */
        case 'c':
            /* code */
            break;

        /* avanca a data do sistema */
        case 't':
            get_data();
        }
    }

    return 0;
}