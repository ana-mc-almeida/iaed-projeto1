/*
 * File:
 * Author:
 * Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
 * #include "global_defines.c"
 * #include "global_defines.c"
 * #include "global_defines.c"
 * #include "global_defines.c"
 * #include "global_defines.c"
 */

/* Numero maximo de airportos suportados */
#define MAXAIRPORTS 40
/* Numero maximo de voos */
#define MAXFLIGHTS 30000
/* Numero de caracteres maximo de um pais */
#define MAXCOUNTRY 30
/* Numero de caracteres maximo de um cidade */
#define MAXCITY 50

#define LEN_ID_AIRPORT 4

#define LEN_ID_FLIGHT 7
#define LETRAS_ID 2

#define INITIAL_DAY 1
#define INITIAL_MONTH 1
#define INITIAL_YEAR 2022

#define MAX_INT 11

#define MAX_PASSAGERS 100
#define MIN_PASSAGERS 10

/*
 * #include "global_structs.c"
 * #include "global_structs.c"
 * #include "global_structs.c"
 * #include "global_structs.c"
 * #include "global_structs.c"
 */
typedef struct
{
    int hour;
    int minute;
} Time;

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char id[LEN_ID_AIRPORT];
    char country[MAXCOUNTRY];
    char city[MAXCITY];
} Airport;

typedef struct
{
    char id[LEN_ID_FLIGHT];
    char airport_departure[LEN_ID_AIRPORT];
    char airport_arrival[LEN_ID_AIRPORT];
    Date date_departure;
    Time time_departure;
    Time duration;
    int max_passengers;
} Flight;

/*
 * #include "global_variables.c"
 * #include "global_variables.c"
 * #include "global_variables.c"
 * #include "global_variables.c"
 * #include "global_variables.c"
 */

Airport currente_airports[MAXAIRPORTS];
int numAirports = 0;

Flight currente_flights[MAXFLIGHTS];
int numFlights = 0;

Date current_date = {INITIAL_DAY, INITIAL_MONTH, INITIAL_YEAR};

char current_char = ' ';

int days_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
 * #include "general_gets.c"
 * #include "general_gets.c"
 * #include "general_gets.c"
 * #include "general_gets.c"
 * #include "general_gets.c"
 */

void remove_spaces()
{
    current_char = getchar();
    while (isspace(current_char))
    {
        current_char = getchar();
    }

    /* printf("CURRENTE CHAR %c\n", current_char); */
}

void finish_line()
{
    while (current_char != '\n')
        current_char = getchar();
}

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
    /* printf("ID %s\n", s); */
}

void get_IDAirport(char s[])
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
    /* printf("ID %s\n", s); */
}

void get_pais(char s[])
{
    int i = 0;

    remove_spaces();

    while (!isspace(current_char))
    {
        s[i] = current_char;
        i++;
        current_char = getchar();
    }
    s[i] = '\0';
    /* printf("PAIS %s\n", s); */
}

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
    /* printf("CIDADE %s\n", s); */
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

int potency(int base, int exponent)
{
    int result = 1, i;
    for (i = 1; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

Date get_date()
{
    Date date;
    scanf("%d-%d-%d", &date.day, &date.month, &date.year);

    if (isdigit(current_char))
        date.day += (current_char - '0') * 10;

    return date;
}

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

int check_invalid_date(Date new_date)
{
    int flag = 1, n_date, c_date;

    c_date = date_to_int(current_date);
    n_date = date_to_int(new_date);
    if (n_date < c_date || n_date - c_date > 10000)
        flag = 0;

    return flag;
}

/* retorna True caso as datas dadas sejam iguais */
int same_dates(Date d1, Date d2)
{
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        return 1;
    return 0;
}

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

int check_duplicate_airport(char s[])
{
    int flag = 1, i;
    for (i = 0; i < numAirports; i++)
    {
        if (strcmp(currente_airports[i].id, s) == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

/*
 * #include "function_add_airport.c"
 * #include "function_add_airport.c"
 * #include "function_add_airport.c"
 * #include "function_add_airport.c"
 * #include "function_add_airport.c"
 */

int check_invalid_airportID(char s[])
{
    int flag = 1, i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (islower(s[i]))
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

void add_airport()
{
    char id[LEN_ID_AIRPORT];
    Airport airport;

    get_word(id);
    if (!check_invalid_airportID(id))
    {
        printf("invalid airport ID\n");
        finish_line();
    }
    else if (numAirports == MAXAIRPORTS)
    {
        printf("too many airports\n");
        finish_line();
    }
    else if (!check_duplicate_airport(id))
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

/*
 * #include "function_list_airports.c"
 * #include "function_list_airports.c"
 * #include "function_list_airports.c"
 * #include "function_list_airports.c"
 * #include "function_list_airports.c"
 */

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
    {
        for (j = 0; j < numAirports - 1 - i; j++)
        {
            if (strcmp(ids[j], ids[j + 1]) > 0)
            {
                strcpy(temp, ids[j]);
                strcpy(ids[j], ids[j + 1]);
                strcpy(ids[j + 1], temp);
            }
        }
    }

    /* apagar depois
    for (i = 0; i < numAirports; i++)
    {
        printf("%s\n", ids[i]);
    }
    */
}

void print_airport(int i, char id[])
{
    int flights;
    flights = get_numFlights(id);
    printf("%s %s %s %d\n", currente_airports[i].id, currente_airports[i].city, currente_airports[i].country, flights);
}

void list_airports()
{
    char id[LEN_ID_AIRPORT], ids[MAXAIRPORTS][LEN_ID_AIRPORT];
    int i, j, flag = 1;

    /* print_airports(); */
    /*while (current_char != '\n')
    {*/

    current_char = getchar();
    /* printf("CURRENT CHAR - %c", current_char); */
    if (current_char != '\n') /* significa que tem pelo menos um id */
    {
        get_word(id);
        while (flag)
        {
            if (current_char == '\n')
                flag = 0;
            i = find_airport_index(id);
            if (i == numAirports)
                printf("%s: no such airport ID\n", id);
            else
            {
                print_airport(i, id);
            }
            if (flag)
                get_word(id);
        }
    }
    else
    {
        for (i = 0; i < numAirports; i++)
        {
            strcpy(ids[i], currente_airports[i].id);
        }

        sort_ids(ids);

        for (j = 0; j < numAirports; j++)
        {
            i = find_airport_index(ids[j]);
            print_airport(i, id);
        }
    }
}

/*
 * #include "function_add_or_list_flights.c"
 * #include "function_add_or_list_flights.c"
 * #include "function_add_or_list_flights.c"
 * #include "function_add_or_list_flights.c"
 * #include "function_add_or_list_flights.c"
 */

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

int check_invalid_flightID(char s[])
{
    int flag = 1, i;

    for (i = 0; i < LETRAS_ID; i++)
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

int check_duplicate_flight(Flight flight)
{
    int flag = 1, i;
    for (i = 0; i < numFlights; i++)
    {
        if (strcmp(currente_flights[i].id, flight.id) == 0 &&
            same_dates(currente_flights[i].date_departure, flight.date_departure))
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
        printf("invalid flight code\n");
        finish_line();
        flag = 0;
    }
    else if (!check_duplicate_flight(flight))
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
    else if (check_duplicate_airport(flight.airport_arrival))
    {
        printf("%s: no such airport ID\n", flight.airport_arrival);
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

/*
 * #include "function_increase_date.c"
 * #include "function_increase_date.c"
 * #include "function_increase_date.c"
 * #include "function_increase_date.c"
 * #include "function_increase_date.c"
 */

void increase_date()
{
    Date new_date;

    new_date = get_date();

    /*print_date(new_date);*/

    if (!check_invalid_date(new_date))
        printf("invalid date\n");
    else
    {
        current_date = new_date;
        print_date(current_date);
        putchar('\n');
    }
}

/*
 * #include "function_list__departure_flights.c"
 * #include "function_list__departure_flights.c"
 * #include "function_list__departure_flights.c"
 * #include "function_list__departure_flights.c"
 * #include "function_list__departure_flights.c"
 */

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

/*
 * #include "function_list_arrival_flights.c"
 * #include "function_list_arrival_flights.c"
 * #include "function_list_arrival_flights.c"
 * #include "function_list_arrival_flights.c"
 * #include "function_list_arrival_flights.c"
 */

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
    if (arrival.minute >= 60)
    {
        arrival.minute -= 60;
        arrival.hour++;
    }
    return arrival;
}

int get_arriving_flights(char id[], Flight arriving_flights[])
{
    int i, num_flights = 0;
    for (i = 0; i < numFlights; i++)
        if (strcmp(currente_flights[i].airport_arrival, id) == 0)
        {
            arriving_flights[num_flights] = currente_flights[i];
            num_flights++;
        }

    return num_flights;
}

void set_arriving_time(Flight flights[], int num_flights)
{
    int i;
    for (i = 0; i < num_flights; i++)
    {
        /* time_departure passa a ser a hora de chegada */
        flights[i].time_departure = get_arrival_time(flights[i].time_departure, flights[i].duration);
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
    if (check_duplicate_airport(id))
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

/*
 * MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN
 * MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN
 * MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN
 * MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN
 * MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN
 */
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
            list_arrival_flights();
            break;

        /* avanca a data do sistema */
        case 't':
            increase_date();
        }
        /*printf("-- %c", current_char);*/
    }

    return 0;
}