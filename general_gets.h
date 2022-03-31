/*
 * File:
 * Author:
 * Description:
 */

#ifndef GENERAL_FUNCTIONS
#define GENERAL_FUNCTIONS

#include "headers.h"

void remove_spaces()
{
    current_char = getchar();
    while (isspace(current_char))
        current_char = getchar();
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

/* retorna o numero de digitos de um numero */
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

/* retorna a potencia exponent de base */
int potency(int base, int exponent)
{
    int result = 1, i;

    for (i = 1; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}

/* le uma data */
Date get_date()
{
    Date date;

    scanf("%d-%d-%d", &date.day, &date.month, &date.year);

    if (isdigit(current_char))
        date.day += (current_char - '0') * 10;

    return date;
}

/* le uma hora */
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

/* retorna 1 caso a data recebida uma
data no passado ou mais de um ano no futuro */
int isValid_date(Date new_date)
{
    int n_date, c_date;

    c_date = date_to_int(current_date);
    n_date = date_to_int(new_date);

    if (n_date < c_date || n_date - c_date > 10000)
        return 0;

    return 1;
}

/* retorna 1 caso as datas dadas sejam iguais */
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

void sort_flights(Flight flights[], int size, int state)
{
    Flight temp;
    int i, j, present_date, next_date, present_time, next_time;

    for (i = 0; i < size; i++)
        for (j = 0; j < size - 1 - i; j++)
        {
            if (state == ARRIVING)
            {
                present_date = date_to_int(flights[j].date_arrival);
                next_date = date_to_int(flights[j + 1].date_arrival);
            }
            else
            {
                present_date = date_to_int(flights[j].date_departure);
                next_date = date_to_int(flights[j + 1].date_departure);
            }

            if (present_date > next_date)
            {
                temp = flights[j];
                flights[j] = flights[j + 1];
                flights[j + 1] = temp;
            }
            else if (present_date == next_date)
            {
                if (state == ARRIVING)
                {
                    present_time = time_to_int(flights[j].time_arrival);
                    next_time = time_to_int(flights[j + 1].time_arrival);
                }
                else
                {
                    present_time = time_to_int(flights[j].time_departure);
                    next_time = time_to_int(flights[j + 1].time_departure);
                }

                if (present_time > next_time)
                {
                    temp = flights[j];
                    flights[j] = flights[j + 1];
                    flights[j + 1] = temp;
                }
            }
        }
}

/* retorna 1 caso o id de aeroporto recebido ja exista */
int exists_airport(char s[])
{
    int i;
    for (i = 0; i < numAirports; i++)
        if (strcmp(currente_airports[i].id, s) == 0)
            return 1;
    return 0;
}

/* obter o numero de voos que saiem/chegam do/ao aeroporto com o id dado */

int get_flights(char id[], Flight flights[], int state)
{
    int i, count_flights = 0;

    char airport_id[LEN_ID_AIRPORT];

    for (i = 0; i < numFlights; i++)
    {
        if (state == ARRIVING)
            strcpy(airport_id, currente_flights[i].airport_arrival);
        else
            strcpy(airport_id, currente_flights[i].airport_departure);

        if (strcmp(airport_id, id) == 0)
        {
            flights[count_flights] = currente_flights[i];
            count_flights++;
        }
    }

    return count_flights;
}

#endif
