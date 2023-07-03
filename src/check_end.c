/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-nicolas1.nguyen
** File description:
** check_end
*/

#include <my_sokoban.h>

int victory_condition(game_t *g, int i, int j)
{
    int count = 0;

    if (g->m->map[i][j] == 'O' && g->m->move[i][j] == 'X') {
        count++;
    }
    return count;
}

int loose_condtion(game_t *g, int i, int j)
{
    int count = 0;

    if (g->m->move[i][j] == 'X'
        && ((g->m->move[i][j - 1] == '#' && g->m->move[i - 1][j] == '#')
        || (g->m->move[i][j - 1] == '#' && g->m->move[i + 1][j] == '#')
        || (g->m->move[i][j + 1] == '#' && g->m->move[i - 1][j] == '#')
        || (g->m->move[i][j + 1] == '#' && g->m->move[i + 1][j] == '#')))
        count++;
    return count;
}

void check_victory(game_t *g)
{
    int count = 0;

    for (int i = 0; i < g->m->lines; i++) {
        for (int j = 0; j < g->m->cols; j++) {
            count += victory_condition(g, i, j);
        }
    }
    if (count == g->count_o) {
        destroy_all(g);
        exit(0);
    }
}

void check_loose(game_t *g)
{
    int count = 0;

    for (int i = 0; i < g->m->lines; i++) {
        for (int j = 0; j < g->m->cols; j++) {
            count += loose_condtion(g, i, j);
        }
    }
    if (count == g->count_x) {
        destroy_all(g);
        exit(1);
    }
}
