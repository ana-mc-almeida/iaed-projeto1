/*
 * File:
 * Author:
 * Description:
 */

#ifndef STRUCTS
#define STRUCTS

#include "headers.h"

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
    Date date_arrival;
    Time time_arrival;
} Flight;

#endif
