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

#endif