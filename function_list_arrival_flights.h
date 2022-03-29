/*
 * File:
 * Author:
 * Description:
 */

#include "headers.h"

Date next_day(Date date)
{
    date.day++;
    /* muda de mes */
    if (date.day > days_of_month[date.month - 1])
    {
        date.day = 1;
        date.month++;

        /* muda de ano */
        if (date.month > 12)
        {
            date.month = 1;
            date.year++;
        }
    }
    return date;
}

Time get_arrival_time(Time departure, Time duration)
{
    Time arrival;

    arrival.hour = departure.hour + duration.hour;
    arrival.minute = departure.minute + duration.minute;

    /* muda de hora */
    if (arrival.minute >= 60)
    {
        arrival.minute -= 60;
        arrival.hour++;
    }

    return arrival;
}

int get_arriving_flights(char id[], Flight arriving_flights[])
{
    int i, count_flights = 0;

    for (i = 0; i < numFlights; i++)
        if (strcmp(currente_flights[i].airport_arrival, id) == 0)
        {
            arriving_flights[count_flights] = currente_flights[i];
            count_flights++;
        }

    return count_flights;
}

void set_arriving_time(Flight flights[], int num_flights)
{
    int i;

    for (i = 0; i < num_flights; i++)
    {
        /* time_departure passa a ser a hora de chegada */
        flights[i].time_departure = get_arrival_time(
            flights[i].time_departure,
            flights[i].duration);

        /* muda a hora */
        if (flights[i].time_departure.hour >= 24)
        {
            flights[i].time_departure.hour -= 24;
            /* date_departure passa a ser a hora de chegada */
            flights[i].date_departure = next_day(flights[i].date_departure);
        }
    }
}

void list_arrival_flights()
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
        num_flights = get_arriving_flights(id, flights);
        set_arriving_time(flights, num_flights);
        sort_flights(flights, num_flights);

        for (i = 0; i < num_flights; i++)
        {
            printf("%s %s ", flights[i].id, flights[i].airport_departure);
            print_date(flights[i].date_departure);
            putchar(' ');
            print_time(flights[i].time_departure);
            putchar('\n');
        }
    }
}