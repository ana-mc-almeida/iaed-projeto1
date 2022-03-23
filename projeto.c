#include "add_aeroport.c"

void list_airports()
{
    char id[LEN_ID_AEROPORT];
    while (current_char != '\n')
    {
        get_IDAeroport(id);
        if (id[0] != '\n')
        {
        }
    }
}

int main()
{

    while (current_char != EOF)
    {
        /* obter carater indicativo da operacao */
        current_char = getchar();
        /* absorver o espaco que vem sempre a seguir */
        getchar();

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
            /* code */
            break;

        /* adiciona um novo voo ou lista todos os voos */
        case 'v':
            /* code */
            break;

        /* lista os voos com partida de um aeroporto */
        case 'p':
            /* code */
            break;

        /* lista os voos com chegada a um aeroporto */
        case 'c':
            /* code */
            break;

        /* avanca a data do sistema */
        case 't':
            get_data();
        }
    }

    return 0;
}