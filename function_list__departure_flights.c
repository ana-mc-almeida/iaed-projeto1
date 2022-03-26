/*
 * File:
 * Author:
 * Description:
 */

#include "headers.c"

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
/*
void sort_flights(Flight flights[], int size)
{
    Flight temp;
    int i, j, i_date, j_date, i_time, j_time;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            i_date = date_to_int(flights[j].date_departure);
            j_date = date_to_int(flights[j + 1].date_departure);
            if (i_date > j_date)
            {
                temp = flights[i];
                flights[i] = flights[j];
                flights[j] = temp;
            }
            else if (i_date == j_date)
            {
                i_time = time_to_int(flights[j].time_departure);
                j_time = time_to_int(flights[j + 1].time_departure);
                if (i_time > j_time)
                {
                    temp = flights[i];
                    flights[i] = flights[j];
                    flights[j] = temp;
                }
            }
        }
    }
}
*/

void sort_flights(Flight flights[], int size)
{
    Flight temp;
    int i, j, present_date, next_date, present_time, next_time;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            present_date = date_to_int(flights[j].date_departure);
            next_date = date_to_int(flights[j + 1].date_departure);
            if (present_date > next_date)
            {
                temp = flights[j];
                flights[j] = flights[j + 1];
                flights[j + 1] = temp;
            }
            else if (present_date == next_date)
            {
                present_time = time_to_int(flights[j].time_departure);
                next_time = time_to_int(flights[j + 1].time_departure);
                if (present_time > next_time)
                {
                    temp = flights[j];
                    flights[j] = flights[j + 1];
                    flights[j + 1] = temp;
                }
            }
        }
    }
}

void list_departure_flights()
{
    Flight flights[MAXFLIGHTS];
    char id[LEN_ID_AIRPORT];
    int num_flights, i;

    get_word(id);
    if (check_duplicate_airport(id))
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