/*
 * File:
 * Author:
 * Description:
 */

#include "headers.h"

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