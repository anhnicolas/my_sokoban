/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-nicolas1.nguyen
** File description:
** main
*/

#include <my_sokoban.h>
#include <my_utils.h>

int main(int ac, char **av)
{
    game_t *g;

    if (error(ac, av) == 84)
        return 84;
    if (print_usage(ac, av) == 0)
        return 0;
    g = initialise_game(av[1]);
    if (g == NULL || invalid_map(g->m->buffer) == 84)
        return 84;
    init_window();
    game_loop(g);
    destroy_all(g);
    return 0;
}
