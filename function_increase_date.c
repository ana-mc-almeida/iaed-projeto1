/*
 * File:
 * Author:
 * Description:
 */

#include "headers.c"

Date get_data()
{
    Date date;
    scanf("%d-%d-%d", &date.day, &date.month, &date.year);
    return date;
}

int check_invalid_date(Date new_date)
{
    int flag = 1, n_date, c_date;

    c_date = current_date.year * 10000 + current_date.month * 100 + current_date.day;
    n_date = new_date.year * 10000 + new_date.month * 100 + new_date.day;
    if (n_date < c_date || n_date - c_date > 10000)
        flag = 0;

    return flag;
}

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
