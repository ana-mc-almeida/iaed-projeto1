/*
 * File:
 * Author:
 * Description:
 */

#include "headers.c"

void increase_date()
{
    Date new_date;

    remove_spaces();
    new_date = get_data();

    if (!check_invalid_date(new_date))
        printf("invalid date\n");
    else
    {
        current_date = new_date;
        print_date(current_date);
    }
}
