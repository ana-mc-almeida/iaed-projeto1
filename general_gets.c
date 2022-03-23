#include "headers.c"

Date get_data()
{
    Date date;
    scanf("%d-%d-%d", &date.day, &date.month, &date.year);
    return date;
}

void get_IDAeroport(char s[])
{
    int i = 0;
    current_char = getchar();
    while (!isspace(current_char) && current_char != '\n')
    {
        s[i] = current_char;
        i++;
        current_char = getchar();
    }
    s[i] = '\0';
}

void get_pais(char s[])
{
    char current_char;
    int i = 0;
    while (!isspace(current_char = getchar()))
    {
        s[i] = current_char;
        i++;
    }
    s[i] = '\0';
}

void get_city(char s[])
{
    char current_char;
    int i = 0;
    while ((current_char = getchar()) != '\n')
    {
        s[i] = current_char;
        i++;
    }
    s[i] = '\0';
}
