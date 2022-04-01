/*
 * File: proj1.c
 * Author: Ana Margarida Almeida
 * Description:
 */

#include "headers.h"

/* ---------- #include "general_gets.h" ---------- */

/* le todos os espacos em branco */
void remove_spaces()
{
    current_char = getchar();
    while (isspace(current_char))
        current_char = getchar();
}

/* le ate encontrar um \n */
void finish_line()
{
    while (current_char != '\n')
        current_char = getchar();
}

/* obtem a palavra seguinte */
void get_word(char s[])
{
    int i = 0;

    remove_spaces();

    while (!isspace(current_char) && current_char != '\n')
    {
        s[i] = current_char;
        i++;
        current_char = getchar();
    }
    s[i] = '\0';
}

/* imprimir horas no formato HH:MM */
void print_time(Time time)
{
    printf("%02d:%02d", time.hour, time.minute);
}

/* imprimir data no formato DD-MM-AAAA */
void print_date(Date date)
{
    printf("%02d-%02d-%d", date.day, date.month, date.year);
}

/* retorna o numero de digitos de um numero */
int get_numDigits(int num)
{
    int digits = 0;

    while (num != 0)
    {
        num /= 10;
        digits++;
    }

    return digits;
}

/* retorna a potencia exponent de base */
int potency(int base, int exponent)
{
    int result = 1, i;

    for (i = 1; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}

/* le uma data */
Date get_date()
{
    Date date;

    scanf("%d-%d-%d", &date.day, &date.month, &date.year);

    if (isdigit(current_char))
        date.day += (current_char - '0') * 10;

    return date;
}

/* le uma hora */
Time get_time()
{
    Time time;

    scanf("%d:%d", &time.hour, &time.minute);

    return time;
}

/* Converte uma data para um inteiro AAAAMMDD */
int date_to_int(Date date)
{
    return date.year * 10000 + date.month * 100 + date.day;
}

/* Converte uma hora para um inteiro HHMM */
int time_to_int(Time time)
{
    return time.hour * 100 + time.minute;
}

/* retorna 1 caso a data recebida uma
data no passado ou mais de um ano no futuro */
int isValid_date(Date new_date)
{
    int n_date, c_date;

    c_date = date_to_int(current_date);
    n_date = date_to_int(new_date);

    if (n_date < c_date || n_date - c_date > 10000)
        return 0;

    return 1;
}

/* retorna 1 caso as datas dadas sejam iguais */
int same_dates(Date d1, Date d2)
{
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        return 1;
    return 0;
}

/* imprimir voo formato pedido */
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

/* ordena os voos pela ordem de partida ou chegada */
void sort_flights(Flight flights[], int size, int state)
{
    Flight temp;
    int i, j, present_date, next_date, present_time, next_time;

    for (i = 0; i < size; i++)
        for (j = 0; j < size - 1 - i; j++)
        {
            if (state == ARRIVING)
            {
                present_date = date_to_int(flights[j].date_arrival);
                next_date = date_to_int(flights[j + 1].date_arrival);
            }
            else
            {
                present_date = date_to_int(flights[j].date_departure);
                next_date = date_to_int(flights[j + 1].date_departure);
            }

            if (present_date > next_date)
            {
                temp = flights[j];
                flights[j] = flights[j + 1];
                flights[j + 1] = temp;
            }
            else if (present_date == next_date)
            {
                if (state == ARRIVING)
                {
                    present_time = time_to_int(flights[j].time_arrival);
                    next_time = time_to_int(flights[j + 1].time_arrival);
                }
                else
                {
                    present_time = time_to_int(flights[j].time_departure);
                    next_time = time_to_int(flights[j + 1].time_departure);
                }

                if (present_time > next_time)
                {
                    temp = flights[j];
                    flights[j] = flights[j + 1];
                    flights[j + 1] = temp;
                }
            }
        }
}

/* retorna 1 caso o id de aeroporto recebido ja exista */
int exists_airport(char s[])
{
    int i;
    for (i = 0; i < numAirports; i++)
        if (strcmp(currente_airports[i].id, s) == 0)
            return 1;
    return 0;
}

/* obter o numero de voos que saiem/chegam do/ao aeroporto com o id dado */
int get_flights(char id[], Flight flights[], int state)
{
    int i, count_flights = 0;

    char airport_id[LEN_ID_AIRPORT];

    for (i = 0; i < numFlights; i++)
    {
        if (state == ARRIVING)
            strcpy(airport_id, currente_flights[i].airport_arrival);
        else
            strcpy(airport_id, currente_flights[i].airport_departure);

        if (strcmp(airport_id, id) == 0)
        {
            flights[count_flights] = currente_flights[i];
            count_flights++;
        }
    }

    return count_flights;
}

/* --------- #include "function_add_airport.h" ----------*/

/* obtem o nome da cidade */
void get_city(char s[])
{
    int i = 0;

    remove_spaces();

    while (current_char != '\n')
    {
        s[i] = current_char;
        i++;
        current_char = getchar();
    }
    s[i] = '\0';
}

/* retorna 1 caso todas as letras do id sejam maiusculas */
int is_valid_airportID(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (islower(s[i]))
            return 0;
    return 1;
}

/* adiciona um novo aeroporto ao sistema */
void add_airport()
{
    char id[LEN_ID_AIRPORT];
    Airport airport;

    get_word(id);

    if (!is_valid_airportID(id))
    {
        printf("invalid airport ID\n");
        finish_line();
    }
    else if (numAirports == MAXAIRPORTS)
    {
        printf("too many airports\n");
        finish_line();
    }
    else if (exists_airport(id))
    {
        printf("duplicate airport\n");
        finish_line();
    }
    else
    {
        strcpy(airport.id, id);

        get_word(airport.country);
        get_city(airport.city);

        currente_airports[numAirports] = airport;
        numAirports++;

        printf("airport %s\n", airport.id);
    }
}

/* ---------- #include "function_list_airports.h" --------- */

/* encontrar o index do aeroporto que tem o id dado */
int find_airport_index(char id[])
{
    int i;

    for (i = 0; i < numAirports; i++)
        if (strcmp(currente_airports[i].id, id) == 0)
            break;

    return i;
}

/* obter o numero de voos que saiem do aeroporto com o id dado */
int get_numFlights(char id[])
{
    int i, count = 0;

    for (i = 0; i < numFlights; i++)
        if (strcmp(currente_flights[i].id, id) == 0)
            count++;

    return count;
}

/* colocar os ids por ordem alfabetica */
void sort_ids(char ids[][LEN_ID_AIRPORT])
{
    char temp[LEN_ID_AIRPORT];
    int i, j;

    for (i = 0; i < numAirports - 1; i++)
        for (j = 0; j < numAirports - 1 - i; j++)
            if (strcmp(ids[j], ids[j + 1]) > 0)
            {
                strcpy(temp, ids[j]);
                strcpy(ids[j], ids[j + 1]);
                strcpy(ids[j + 1], temp);
            }
}

/* faz print do aeroporto no formato pedido */
void print_airport(int i, char id[])
{
    int flights;

    flights = get_numFlights(id);

    printf("%s %s %s %d\n",
           currente_airports[i].id,
           currente_airports[i].city,
           currente_airports[i].country,
           flights);
}

/* lista os aeroportos */
void list_airports()
{
    char id[LEN_ID_AIRPORT];
    int i, j;
    /* array onde seram guardados e ordenados os ids dos aeroportos */
    char ids[MAXAIRPORTS][LEN_ID_AIRPORT];
    /* flag que indica se ha mais ids por ler */
    int last_id = 0;

    current_char = getchar();

    if (current_char != '\n') /* significa que tem pelo menos um id */
    {
        get_word(id);

        while (!last_id)
        {
            if (current_char == '\n')
                last_id = 1;

            i = find_airport_index(id);

            if (i == numAirports)
                printf("%s: no such airport ID\n", id);
            else
                print_airport(i, id);

            if (!last_id)
                get_word(id);
        }
    }
    else
    {
        for (i = 0; i < numAirports; i++)
            strcpy(ids[i], currente_airports[i].id);

        sort_ids(ids);

        for (j = 0; j < numAirports; j++)
        {
            i = find_airport_index(ids[j]);
            print_airport(i, id);
        }
    }
}

/* --------- #include "function_add_or_list_flights.h" --------- */

/* printa todos os voos */
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

/* le o numero de passageiros */
int get_passengers()
{
    char passengers_string[MAX_INT];
    int passengers;

    get_word(passengers_string);
    passengers = atoi(passengers_string);

    return passengers;
}

/* retorna 1 caso o id de voo recebido seja um id valido */
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

/* indica se ja existe um voo com o mesmo id para o mesmo dia */
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

/* indica de o numero de passageiros esta dentro os limites permitidos */
int isValid_capacity(int passagers)
{
    if (passagers < MIN_PASSAGERS || passagers > MAX_PASSAGERS)
        return 0;
    return 1;
}

/* verifica se existe algum erro com o voo */
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

/* adiciona um novo voo ou lista todos os voos */
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

/* --------- #include "function_list_departure_flights.h" -------- */

/* lista os voos com partida de um aeroporto */
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

/* --------- #include "function_list_arrival_flights.h" --------- */

/* retorna o dia a seguir ao dia dado */
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

/* junta a duracao a hora de partida para retornar a hora de chegada */
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

/* adiciona a hora de chegada aos voos */
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

/* lista os voos com chegada a um aeroporto */
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

/* ---------- #include "function_increase_date.h" --------- */

/* avanca a data do sistema */
void increase_date()
{
    Date new_date;

    new_date = get_date();

    if (!isValid_date(new_date))
        printf("invalid date\n");
    else
    {
        current_date = new_date;
        print_date(current_date);
        putchar('\n');
    }
}

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