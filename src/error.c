/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-nicolas1.nguyen
** File description:
** error
*/

#include <my_sokoban.h>

int invalid_map(char *buffer)
{
    int count = 0;
    int count_player = 0;
    int count_o = 0;
    int count_x = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != ' ' && buffer[i] != 'X' && buffer[i] != 'O'
            && buffer[i] != '#' && buffer[i] != 'P' && buffer[i] != '\n')
            count ++;
        if (buffer[i] == 'P')
            count_player++;
        if (buffer[i] == 'O')
            count_o++;
        if (buffer[i] == 'X')
            count_x++;
    }
    if (count > 0 || count_player != 1 || count_x < count_o)
        return 84;
    else
        return 0;
}

int print_usage(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        write(1, "USAGE\n\t./my_sokoban map\nDESCRIPTION\n", 37);
        write(1, "\tmap file representing the warehouse map, containing ", 54);
        write(1, "'#' for walls, 'P' for the player, 'X' for boxes and ", 54);
        write(1, "'O' for storage locations.\n", 28);
        return 0;
    }
}

int error(int ac, char **av)
{
    if (ac != 2) {
        write(2, "Bad number of arguments.\n", 26);
        return 84;
    }
}
