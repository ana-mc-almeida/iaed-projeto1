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

void set_arriving_time(Flight flights[], int num_flights)
{
    int i;

    for (i = 0; i < num_flights; i++)
    {
        flights[i].date_arrival = flights[i].date_departure;

        flights[i].time_arrival = get_arrival_time(
            flights[i].time_departure,
            flights[i].duration);

        /* muda a hora */
        if (flights[i].time_arrival.hour >= 24)
        {
            flights[i].time_arrival.hour -= 24;
            flights[i].date_arrival = next_day(flights[i].date_arrival);
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
        num_flights = get_flights(id, flights, ARRIVING);
        set_arriving_time(flights, num_flights);
        sort_flights(flights, num_flights, ARRIVING);

        for (i = 0; i < num_flights; i++)
        {
            printf("%s %s ", flights[i].id, flights[i].airport_departure);
            print_date(flights[i].date_arrival);
            putchar(' ');
            print_time(flights[i].time_arrival);
            putchar('\n');
        }
    }
}