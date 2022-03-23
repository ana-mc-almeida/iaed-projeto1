#include "general_gets.c"

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
    for (i = 0; i < numAirports; i++)
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
    char id[LEN_ID_AIRPORT];
    Airport airport;

    get_IDAeroport(id);
    if (!check_invalid_airportID(id))
        printf("invalid airports ID\n");
    else if (numAirports + 1 >= MAXAIRPORTS)
        printf("too many airports\n");
    else if (!check_duplicate_airport(id))
        printf("duplicate airport\n");
    else
    {
        strcpy(airport.id, id);
        get_pais(airport.country);
        get_city(airport.city);
        airports[numAirports] = airport;
        numAirports++;

        printf("airport %s\n", airport.id);
    }
}
