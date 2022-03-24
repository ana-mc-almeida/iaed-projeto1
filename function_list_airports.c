/*
 * File:
 * Author:
 * Description:
 */

#include "headers.c"

/* encontrar o index do aeroporto que tem o id dado */
int find_airport_index(char id[])
{
    int i;

    for (i = 0; i < numAirports; i++)
        if (strcmp(airports[i].id, id) == 0)
            break;

    return i;
}

/* obter o numero de voos que saiem do aeroporto com o id dado */
int get_numFlights(char id[])
{
    int i;
    for (i = 0; i < numFlights; i++)
        if (strcmp(flights[i].airport_departure.id, id) == 0)
            break;

    return i;
}

/* colocar os ids por ordem alfabetica */
void order_ids(char ids[][LEN_ID_AIRPORT])
{
    char temp[LEN_ID_AIRPORT];
    int i, j;

    for (i = 0; i < numAirports - 1; i++)
    {
        for (j = 0; j < numAirports - 1 - i; j++)
        {
            if (strcmp(ids[j], ids[j + 1]) > 0)
            {
                strcpy(temp, ids[j]);
                strcpy(ids[j], ids[j + 1]);
                strcpy(ids[j + 1], temp);
            }
        }
    }

    /* apagar depois
    for (i = 0; i < numAirports; i++)
    {
        printf("%s\n", ids[i]);
    }
    */
}

void print_airport(int i, char id[])
{
    int flights;
    flights = get_numFlights(id);
    printf("%s %s %s %d\n", airports[i].id, airports[i].city, airports[i].country, flights);
}

void list_airports()
{
    char id[LEN_ID_AIRPORT], ids[MAXAIRPORTS][LEN_ID_AIRPORT];
    int i, j, flag = 1;

    /* print_airports(); */
    /*while (current_char != '\n')
    {*/

    current_char = getchar();
    /* printf("CURRENT CHAR - %c", current_char); */
    if (current_char != '\n') /* significa que tem pelo menos um id */
    {
        get_IDAirport(id);
        while (flag)
        {
            if (current_char == '\n')
                flag = 0;
            i = find_airport_index(id);
            if (i == numAirports)
                printf("%s: no such airport ID\n", id);
            else
            {
                print_airport(i, id);
            }
            if (flag)
                get_IDAirport(id);
        }
    }
    else
    {
        for (i = 0; i < numAirports; i++)
        {
            strcpy(ids[i], airports[i].id);
        }

        order_ids(ids);

        for (j = 0; j < numAirports; j++)
        {
            i = find_airport_index(ids[j]);
            print_airport(i, id);
        }
    }
}
