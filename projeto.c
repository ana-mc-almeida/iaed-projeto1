/*
 * File:
 * Author:
 * Description:
 */

#include "headers.c"

#include "global_helps.c"

#include "general_gets.c"

#include "function_add_airport.c"
#include "function_list_airports.c"
#include "function_add_or_list_flights.c"
#include "function_increase_date.c"
#include "function_list__departure_flights.c"
#include "function_list_arrival_flights.c"

int main()
{
    while (current_char != EOF)
    {
        /* obter carater indicativo da operacao */
        current_char = getchar();
        /* printf("-- CURRENT CHAR %c\n", current_char);*/

        /* absorver o espaco que vem sempre a seguir */
        /* getchar(); */

        switch (current_char)
        {
        /* termina o programa */
        case 'q':
            return 0;
            break;

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
            /* code */
            break;

        /* avanca a data do sistema */
        case 't':
            increase_date();
        }
        /*printf("-- %c", current_char);*/
    }

    return 0;
}