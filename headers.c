/*
 * File:
 * Author:
 * Description:
 */

#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
 * #include "global_defines.c"
 */

/* Numero maximo de airportos suportados */
#define MAXAIRPORTS 40
/* Numero maximo de voos */
#define MAXFLIGHTS 30000
/* Numero de caracteres maximo de um pais */
#define MAXCOUNTRY 30
/* Numero de caracteres maximo de um cidade */
#define MAXCITY 50

#define LEN_ID_AIRPORT 4

#define LEN_ID_FLIGHT 7
#define LETRAS_ID 2

#define INITIAL_DAY 1
#define INITIAL_MONTH 1
#define INITIAL_YEAR 2022

#define MAX_INT 11

#define MAX_PASSAGERS 100
#define MIN_PASSAGERS 10

/*
 * #include "global_structs.c"
 */
typedef struct
{
    int hour;
    int minute;
} Time;

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char id[LEN_ID_AIRPORT];
    char country[MAXCOUNTRY];
    char city[MAXCITY];
} Airport;

typedef struct
{
    char id[LEN_ID_FLIGHT];
    char airport_departure[LEN_ID_AIRPORT];
    char airport_arrival[LEN_ID_AIRPORT];
    Date date_departure;
    Time time_departure;
    Time duration;
    int max_passengers;
} Flight;

/*
 * #include "global_variables.c"
 */

Airport currente_airports[MAXAIRPORTS];
int numAirports = 0;

Flight currente_flights[MAXFLIGHTS];
int numFlights = 0;

Date current_date = {INITIAL_DAY, INITIAL_MONTH, INITIAL_YEAR};

char current_char = ' ';

int days_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
#include "general_gets.c"
*/

void remove_spaces()
{
    current_char = getchar();
    while (isspace(current_char))
    {
        current_char = getchar();
    }

    /* printf("CURRENTE CHAR %c\n", current_char); */
}

void finish_line()
{
    while (current_char != '\n')
        current_char = getchar();
}

void get_word(char s[])
{
    int i = 0;

    remove_spaces();

    while (!isspace(current_char) && current_char != '\n')
    {
        s[i] = current_char;
        i++;
        current_char = getchar();
    }
    s[i] = '\0';
    /* printf("ID %s\n", s); */
}

void get_IDAirport(char s[])
{
    int i = 0;

    remove_spaces();

    while (!isspace(current_char) && current_char != '\n')
    {
        s[i] = current_char;
        i++;
        current_char = getchar();
    }
    s[i] = '\0';
    /* printf("ID %s\n", s); */
}

void get_pais(char s[])
{
    int i = 0;

    remove_spaces();

    while (!isspace(current_char))
    {
        s[i] = current_char;
        i++;
        current_char = getchar();
    }
    s[i] = '\0';
    /* printf("PAIS %s\n", s); */
}

void get_city(char s[])
{
    int i = 0;

    remove_spaces();

    while (current_char != '\n')
    {
        s[i] = current_char;
        i++;
        current_char = getchar();
    }
    s[i] = '\0';
    /* printf("CIDADE %s\n", s); */
}

/* imprimir horas no formato HH:MM */
void print_time(Time time)
{
    printf("%02d:%02d", time.hour, time.minute);
}

/* imprimir data no formato DD-MM-AAAA */
void print_date(Date date)
{
    printf("%02d-%02d-%d", date.day, date.month, date.year);
}

int get_numDigits(int num)
{
    int digits = 0;
    while (num != 0)
    {
        num /= 10;
        digits++;
    }
    return digits;
}

int potency(int base, int exponent)
{
    int result = 1, i;
    for (i = 1; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

Date get_date()
{
    Date date;
    scanf("%d-%d-%d", &date.day, &date.month, &date.year);

    if (isdigit(current_char))
        date.day += (current_char - '0') * 10;

    return date;
}

Time get_time()
{
    Time time;
    scanf("%d:%d", &time.hour, &time.minute);
    return time;
}

/* Converte uma data para um inteiro AAAAMMDD */
int date_to_int(Date date)
{
    return date.year * 10000 + date.month * 100 + date.day;
}

/* Converte uma hora para um inteiro HHMM */
int time_to_int(Time time)
{
    return time.hour * 100 + time.minute;
}

int check_invalid_date(Date new_date)
{
    int flag = 1, n_date, c_date;

    c_date = date_to_int(current_date);
    n_date = date_to_int(new_date);
    if (n_date < c_date || n_date - c_date > 10000)
        flag = 0;

    return flag;
}

/* retorna True caso as datas dadas sejam iguais */
int same_dates(Date d1, Date d2)
{
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        return 1;
    return 0;
}

/* imprimir voo formato pedido */
/* <códigoVoo> <IDAeroportoPartida> <IDAeroportoChegada> <dataPartida> <horaPartida> */
void print_flight(Flight flight)
{
    char id_flight[LEN_ID_FLIGHT];
    char id_departure[LEN_ID_AIRPORT];
    char id_arrival[LEN_ID_AIRPORT];

    strcpy(id_flight, flight.id);
    strcpy(id_arrival, flight.airport_arrival);
    strcpy(id_departure, flight.airport_departure);

    printf("%s %s %s ", id_flight, id_departure, id_arrival);
    print_date(flight.date_departure);
    putchar(' ');
    print_time(flight.time_departure);
    putchar('\n');
}

/*
int string_to_int(char s[])
{
    int i, n = 0;
    printf("%s\n", s);
    for (i = 0; s[i] != '\0'; i++)
    {
        n = n * 10 + s[i] - '0';
    }
    printf("%d\n", n);
    return n;
}
*/
/*
Date get_date()
{
    Date date;
    char day[3], month[3], year[5];
    remove_spaces();

    scanf("%c%c-%c%c-%c%c%c%c",
          &day[0], &day[1],
          &month[0], &month[1],
          &year[0], &year[1], &year[2], &year[3]);
    day[2] = '\0';
    month[2] = '\0';
    year[4] = '\0';

    date.day = string_to_int(day);
    date.month = string_to_int(month);
    date.year = string_to_int(year);

    return date;
}
*/

void sort_flights(Flight flights[], int size)
{
    Flight temp;
    int i, j, present_date, next_date, present_time, next_time;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            present_date = date_to_int(flights[j].date_departure);
            next_date = date_to_int(flights[j + 1].date_departure);
            if (present_date > next_date)
            {
                temp = flights[j];
                flights[j] = flights[j + 1];
                flights[j + 1] = temp;
            }
            else if (present_date == next_date)
            {
                present_time = time_to_int(flights[j].time_departure);
                next_time = time_to_int(flights[j + 1].time_departure);
                if (present_time > next_time)
                {
                    temp = flights[j];
                    flights[j] = flights[j + 1];
                    flights[j + 1] = temp;
                }
            }
        }
    }
}

int check_duplicate_airport(char s[])
{
    int flag = 1, i;
    for (i = 0; i < numAirports; i++)
    {
        if (strcmp(currente_airports[i].id, s) == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

#endif