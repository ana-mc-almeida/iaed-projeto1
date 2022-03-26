/*
 * File:
 * Author:
 * Description:
 */

#ifndef GENERAL_FUNCTIONS
#define GENERAL_FUNCTIONS

#include "headers.c"

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

#endif