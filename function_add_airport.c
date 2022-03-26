/*
 * File:
 * Author:
 * Description: all functions needed to add airport
 */
#include "headers.c"

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

void add_airport()
{
    char id[LEN_ID_AIRPORT];
    Airport airport;

    get_word(id);
    if (!check_invalid_airportID(id))
    {
        printf("invalid airport ID\n");
        finish_line();
    }
    else if (numAirports == MAXAIRPORTS)
    {
        printf("too many airports\n");
        finish_line();
    }
    else if (!check_duplicate_airport(id))
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
