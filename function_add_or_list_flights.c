/*
 * File:
 * Author:
 * Description:
 */
#include "headers.c"

/* imprimir voo formato pedido */
/* <códigoVoo> <IDAeroportoPartida> <IDAeroportoChegada> <dataPartida> <horaPartida> */
void print_flight(Flight flight)
{
    char id_flight[LEN_ID_FLIGHT];
    char id_departure[LEN_ID_AIRPORT];
    char id_arrival[LEN_ID_AIRPORT];

    strcpy(id_flight, flight.id);
    strcpy(id_arrival, flight.airport_arrival);
    strcpy(id_departure, flight.airport_departure);

    printf("%s %s %s ", id_flight, id_departure, id_arrival);
    print_date(flight.date_departure);
    putchar(' ');
    print_time(flight.time_departure);
    putchar('\n');
}

void list_flights()
{
    int i;
    Flight flight;
    for (i = 0; i < numFlights; i++)
    {
        flight = flights[i];
        print_flight(flight);
    }
}

int get_passengers()
{
    char passengers_string[MAX_INT];
    int i = 0, passengers = 0;
    get_word(passengers_string);
    for (i = 0; passengers_string[i] != '\0'; i++)
    {
        passengers = passengers * 10 + passengers_string[i] - '0';
    }
    return passengers;
}

int check_invalid_flightID(char s[])
{
    int flag = 1, i;

    for (i = 0; i < LETRAS_ID / 2; i++)
    {
        if (islower(s[i]))
        {
            flag = 0;
            break;
        }
    }

    for (i = LETRAS_ID; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

int check_duplicate_flight(char s[])
{
    int flag = 1, i;
    for (i = 0; i < numFlights; i++)
    {
        if (strcmp(flights[i].id, s) == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int check_capacity(int passagers)
{
    int flag = 1;

    if (passagers < MIN_PASSAGERS || passagers > MAX_PASSAGERS)
        flag = 0;
    return flag;
}

int check_flight(Flight flight)
{
    int flag = 1;

    if (!check_invalid_flightID(flight.id))
    {
        printf("invalid flight\n");
        finish_line();
        flag = 0;
    }
    else if (!check_duplicate_flight(flight.id))
    {
        printf("flight already exists\n");
        finish_line();
        flag = 0;
    }
    else if (check_duplicate_airport(flight.airport_departure))
    {
        printf("%s: no such airport ID\n", flight.airport_departure);
        finish_line();
        flag = 0;
    }
    else if (numFlights == MAXFLIGHTS)
    {
        printf("too many flights\n");
        finish_line();
        flag = 0;
    }
    else if (!check_invalid_date(flight.date_departure))
    {
        printf("invalid date\n");
        finish_line();
        flag = 0;
    }
    else if (
        flight.duration.hour > 12 ||
        (flight.duration.hour == 12 &&
         flight.duration.minute != 0))
    {
        printf("invalid duration\n");
        finish_line();
        flag = 0;
    }
    else if (!check_capacity(flight.max_passengers))
    {
        printf("invalid capacity\n");
        finish_line();
        flag = 0;
    }

    return flag;
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
        new_flight.date_departure = get_data();
        new_flight.time_departure = get_time();
        new_flight.duration = get_time();
        new_flight.max_passengers = get_passengers();

        if (check_flight(new_flight))
        {
            flights[numFlights] = new_flight;
            numFlights++;
        }
    }
    else /* listar voos */
    {
        list_flights();
    }
}