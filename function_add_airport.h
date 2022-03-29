/*
 * File:
 * Author:
 * Description: all functions needed to add airport
 */

#include "headers.h"

int is_valid_airportID(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (islower(s[i]))
            return 0;
    return 1;
}

void add_airport()
{
    char id[LEN_ID_AIRPORT];
    Airport airport;

    get_word(id);
    if (!is_valid_airportID(id))
    {
        printf("invalid airport ID\n");
        finish_line();
    }
    else if (numAirports == MAXAIRPORTS)
    {
        printf("too many airports\n");
        finish_line();
    }
    else if (exists_airport(id))
    {
        printf("duplicate airport\n");
        finish_line();
    }
    else
    {
        strcpy(airport.id, id);
        get_word(airport.country);
        get_city(airport.city);
        currente_airports[numAirports] = airport;
        numAirports++;

        printf("airport %s\n", airport.id);
    }
}