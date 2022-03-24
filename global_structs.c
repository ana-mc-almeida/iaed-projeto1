/*
 * File:
 * Author:
 * Description:
 */

#ifndef STRUCTS
#define STRUCTS

#include "headers.c"

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
    Airport airport_departure;
    Airport airport_arrival;
    Date date_departure;
    Time time_departure;
    Time duration;
    int max_passengers;
} Flight;

#endif