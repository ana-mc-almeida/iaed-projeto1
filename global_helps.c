#include "headers.c"

void print_airports()
{
    int i = 0;
    printf("\n**************************\n");
    for (i = 0; i < numAirports; i++)
    {
        Airport a;
        a = airports[i];
        printf("%s - %s - %s\n", a.id, a.country, a.city);
    }
    printf("\n**************************\n");
}