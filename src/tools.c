/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-nicolas1.nguyen
** File description:
** tools
*/

#include <my_sokoban.h>

void init_window(void)
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
}

void destroy(game_t *g)
{
    for (int i = 0; g->m->map[i] != NULL; i++)
        free(g->m->map[i]);
    for (int i = 0; g->m->move[i] != NULL; i++)
        free(g->m->move[i]);
    for (int i = 0; g->m->storage[i] != NULL; i++)
        free(g->m->storage[i]);
    free(g->m->map);
    free(g->m->move);
    free(g->m->storage);
    free(g->m->buffer);
    free(g->m);
    free(g->p);
    for (int i = 0; i < g->count_o; i++)
        free(g->s[i]);
    free(g->s);
    free(g);
}

void destroy_all(game_t *g)
{
    endwin();
    destroy(g);
}

void display_map(map_t *map)
{
    for (int i = 0; i < map->lines; i++) {
        mvprintw((LINES / 2) - (map->lines / 2) + i,
                (COLS / 2) - (map->cols / 2), "%s\n", map->move[i]);
    }
    refresh();
}

void display_original_map(game_t *g)
{
    for (int i = 0; g->m->map[i] != NULL; i++) {
        for (int j = 0; g->m->map[i][j] != '\0'; j++) {
            g->p = coord_p(g->m->map[i][j], i, j, g->p);
            g->m->move[i][j] = g->m->map[i][j];
        }
    }
}
