/*
 * File:
 * Author:
 * Description:
 */

#include "headers.h"

/* obter o numero de voos que saiem do aeroporto com o id dado */
int get_departing_flights(char id[], Flight departing_flights[])
{
    int i, num_flights = 0;
    for (i = 0; i < numFlights; i++)
        if (strcmp(currente_flights[i].airport_departure, id) == 0)
        {
            departing_flights[num_flights] = currente_flights[i];
            num_flights++;
        }

    return num_flights;
}
void list_departure_flights()
{
    Flight flights[MAXFLIGHTS];
    char id[LEN_ID_AIRPORT];
    int num_flights, i;

    get_word(id);
    if (!airport_exists(id))
    {
        printf("%s: no such airport ID\n", id);
        finish_line();
    }
    else
    {
        num_flights = get_departing_flights(id, flights);
        sort_flights(flights, num_flights);

        for (i = 0; i < num_flights; i++)
        {
            printf("%s %s ", flights[i].id, flights[i].airport_arrival);
            print_date(flights[i].date_departure);
            putchar(' ');
            print_time(flights[i].time_departure);
            putchar('\n');
        }
    }
}
