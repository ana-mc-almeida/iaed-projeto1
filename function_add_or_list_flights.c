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
    strcpy(id_arrival, flight.airport_arrival.id);
    strcpy(id_departure, flight.airport_departure.id);

    printf("%s %s %s ", id_flight, id_arrival, id_departure);
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

void add_list_flights()
{
    current_char = getchar();

    if (current_char != '\n') /* adicionar voo */
    {
    }
    else /* listar voos */
    {
        list_flights();
    }
}