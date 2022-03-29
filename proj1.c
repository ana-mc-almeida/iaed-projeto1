/*
 * File:
 * Author:
 * Description:
 */

#include "headers.h"

#include "function_add_airport.h"
#include "function_list_airports.h"
#include "function_add_or_list_flights.h"
#include "function_increase_date.h"
#include "function_list_departure_flights.h"
#include "function_list_arrival_flights.h"

int main()
{
    while (current_char != EOF)
    {
        /* obter carater indicativo da operacao */
        current_char = getchar();

        switch (current_char)
        {
        /* termina o programa */
        case 'q':
            return 0;

        /* adiciona um novo aeroporto ao sistema */
        case 'a':
            add_airport();
            break;

        /* lista os aeroportos */
        case 'l':
            list_airports();
            break;

        /* adiciona um novo voo ou lista todos os voos */
        case 'v':
            add_list_flights();
            break;

        /* lista os voos com partida de um aeroporto */
        case 'p':
            list_departure_flights();
            break;

        /* lista os voos com chegada a um aeroporto */
        case 'c':
            list_arrival_flights();
            break;

        /* avanca a data do sistema */
        case 't':
            increase_date();
        }
    }

    return 0;
}