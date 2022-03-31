/*
 * File:
 * Author:
 * Description:
 */

#include "headers.h"

void list_departure_flights()
{
    Flight flights[MAXFLIGHTS];
    char id[LEN_ID_AIRPORT];
    int num_flights, i;

    get_word(id);
    if (!exists_airport(id))
    {
        printf("%s: no such airport ID\n", id);
        finish_line();
    }
    else
    {
        num_flights = get_flights(id, flights, DEPARTING);
        sort_flights(flights, num_flights, DEPARTING);

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
