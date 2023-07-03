/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-nicolas1.nguyen
** File description:
** my_sokoban
*/

#include <my_sokoban.h>
#include <my_utils.h>

void player_movement(game_t *g, int input)
{
    if (input == KEY_UP) {
        player_up(g, g->m->move, g->p);
        display_map(g->m);
    }
    if (input == KEY_DOWN) {
        player_down(g, g->m->move, g->p);
        display_map(g->m);
    }
    if (input == KEY_RIGHT) {
        player_right(g, g->m->move, g->p);
        display_map(g->m);
    }
    if (input == KEY_LEFT) {
        player_left(g, g->m->move, g->p);
        display_map(g->m);
    }
}

void game_loop(game_t *game)
{
    int input;

    while (1) {
        clear();
        if (game->m->lines > LINES || game->m->cols > COLS)
            mvprintw(LINES / 2 - 1, (COLS / 2) - 35 / 2,
                "Terminal too small, please resize.");
        else
            display_map(game->m);
        input = getch();
        player_movement(game, input);
        check_victory(game);
        check_loose(game);
        if (input == ' ') {
            display_original_map(game);
        }
        if (input == 'q') {
            break;
        }
    }
}
