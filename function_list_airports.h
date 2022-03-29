/*
 * File:
 * Author:
 * Description:
 */

#include "headers.h"

/* encontrar o index do aeroporto que tem o id dado */
int find_airport_index(char id[])
{
    int i;

    for (i = 0; i < numAirports; i++)
        if (strcmp(currente_airports[i].id, id) == 0)
            break;

    return i;
}

/* obter o numero de voos que saiem do aeroporto com o id dado */
int get_numFlights(char id[])
{
    int i, count = 0;

    for (i = 0; i < numFlights; i++)
        if (strcmp(currente_flights[i].id, id) == 0)
            count++;

    return count;
}

/* colocar os ids por ordem alfabetica */
void sort_ids(char ids[][LEN_ID_AIRPORT])
{
    char temp[LEN_ID_AIRPORT];
    int i, j;

    for (i = 0; i < numAirports - 1; i++)
        for (j = 0; j < numAirports - 1 - i; j++)
            if (strcmp(ids[j], ids[j + 1]) > 0)
            {
                strcpy(temp, ids[j]);
                strcpy(ids[j], ids[j + 1]);
                strcpy(ids[j + 1], temp);
            }
}

void print_airport(int i, char id[])
{
    int flights;

    flights = get_numFlights(id);

    printf("%s %s %s %d\n",
           currente_airports[i].id,
           currente_airports[i].city,
           currente_airports[i].country,
           flights);
}

void list_airports()
{
    char id[LEN_ID_AIRPORT];
    int i, j;
    /* array onde seram guardados e ordenados os ids dos aeroportos */
    char ids[MAXAIRPORTS][LEN_ID_AIRPORT];
    /* flag que indica se ha mais ids por ler */
    int last_id = 0;

    current_char = getchar();

    if (current_char != '\n') /* significa que tem pelo menos um id */
    {
        get_word(id);

        while (!last_id)
        {
            if (current_char == '\n')
                last_id = 1;

            i = find_airport_index(id);

            if (i == numAirports)
                printf("%s: no such airport ID\n", id);
            else
                print_airport(i, id);

            if (!last_id)
                get_word(id);
        }
    }
    else
    {
        for (i = 0; i < numAirports; i++)
            strcpy(ids[i], currente_airports[i].id);

        sort_ids(ids);

        for (j = 0; j < numAirports; j++)
        {
            i = find_airport_index(ids[j]);
            print_airport(i, id);
        }
    }
}