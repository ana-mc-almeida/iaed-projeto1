/*
 * File:
 * Author:
 * Description:
 */
#include "headers.h"

void list_flights()
{
    int i;
    Flight flight;
    for (i = 0; i < numFlights; i++)
    {
        flight = currente_flights[i];
        print_flight(flight);
    }
}

int get_passengers()
{
    char passengers_string[MAX_INT];
    int passengers;
    get_word(passengers_string);
    passengers = atoi(passengers_string);
    return passengers;
}

int isValid_flightId(char s[])
{
    int i;

    for (i = 0; i < LETRAS_ID; i++)
        if (islower(s[i]))
            return 0;

    for (i = LETRAS_ID; s[i] != '\0'; i++)
        if (!isdigit(s[i]))
            return 0;

    return 1;
}

int exists_flight(Flight flight)
{
    int i;
    for (i = 0; i < numFlights; i++)
        if (strcmp(currente_flights[i].id, flight.id) == 0 &&
            same_dates(
                currente_flights[i].date_departure,
                flight.date_departure))
            return 1;
    return 0;
}

int isValid_capacity(int passagers)
{
    if (passagers < MIN_PASSAGERS || passagers > MAX_PASSAGERS)
        return 0;
    return 1;
}

int check_flight(Flight flight)
{
    if (!isValid_flightId(flight.id))
    {
        printf("invalid flight code\n");
        finish_line();
        return 0;
    }
    else if (exists_flight(flight))
    {
        printf("flight already exists\n");
        finish_line();
        return 0;
    }
    else if (!exists_airport(flight.airport_departure))
    {
        printf("%s: no such airport ID\n", flight.airport_departure);
        finish_line();
        return 0;
    }
    else if (!exists_airport(flight.airport_arrival))
    {
        printf("%s: no such airport ID\n", flight.airport_arrival);
        finish_line();
        return 0;
    }
    else if (numFlights == MAXFLIGHTS)
    {
        printf("too many flights\n");
        finish_line();
        return 0;
    }
    else if (!isValid_date(flight.date_departure))
    {
        printf("invalid date\n");
        finish_line();
        return 0;
    }
    else if (
        flight.duration.hour > 12 ||
        (flight.duration.hour == 12 &&
         flight.duration.minute != 0))
    {
        printf("invalid duration\n");
        finish_line();
        return 0;
    }
    else if (!isValid_capacity(flight.max_passengers))
    {
        printf("invalid capacity\n");
        finish_line();
        return 0;
    }

    return 1;
}

void add_list_flights()
{
    Flight new_flight;

    current_char = getchar();

    if (current_char != '\n') /* adicionar voo */
    {
        get_word(new_flight.id);
        get_word(new_flight.airport_departure);
        get_word(new_flight.airport_arrival);
        new_flight.date_departure = get_date();
        new_flight.time_departure = get_time();
        new_flight.duration = get_time();
        new_flight.max_passengers = get_passengers();

        if (check_flight(new_flight))
        {
            currente_flights[numFlights] = new_flight;
            numFlights++;
        }
    }
    else /* listar voos */
    {
        list_flights();
    }
}
