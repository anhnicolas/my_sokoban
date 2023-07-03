/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-nicolas1.nguyen
** File description:
** movement
*/

#include <my_sokoban.h>

int p_is_on_storage(game_t *g)
{
    int i = 0;

    while (i < g->count_o) {
        if (g->p->y == g->s[i]->y && g->p->x == g->s[i]->x)
            return 0;
        i++;
    }
    return 1;
}

void player_up(game_t *g, char **move, player_t *player)
{
    if (move[player->y - 1][player->x] == ' '
            || move[player->y - 1][player->x] == 'O') {
        move[player->y - 1][player->x] = 'P';
        move[player->y][player->x] = p_is_on_storage(g) == 0 ? 'O' : ' ';
        player->y -= 1;
        player->x = player->x;
    } else if (move[player->y - 1][player->x] == 'X'
            && (move[player->y - 2][player->x] == ' '
            || move[player->y - 2][player->x] == 'O')) {
        move[player->y - 2][player->x] = 'X';
        move[player->y - 1][player->x] = 'P';
        move[player->y][player->x] = p_is_on_storage(g) == 0 ? 'O' : ' ';
        player->y -= 1;
        player->x = player->x;
    }
}

void player_down(game_t *g, char **move, player_t *player)
{
    if (move[player->y + 1][player->x] == ' '
            || move[player->y + 1][player->x] == 'O') {
        move[player->y + 1][player->x] = 'P';
        move[player->y][player->x] = p_is_on_storage(g) == 0 ? 'O' : ' ';
        player->y += 1;
        player->x = player->x;
    } else if (move[player->y + 1][player->x] == 'X'
            && (move[player->y + 2][player->x] == 'O'
            || move[player->y + 2][player->x] == ' ')) {
        move[player->y + 2][player->x] = 'X';
        move[player->y + 1][player->x] = 'P';
        move[player->y][player->x] = p_is_on_storage(g) == 0 ? 'O' : ' ';
        player->y += 1;
        player->x = player->x;
    }
}

void player_right(game_t *g, char **move, player_t *player)
{
    if (move[player->y][player->x + 1] == ' '
            || move[player->y][player->x + 1] == 'O') {
        move[player->y][player->x + 1] = 'P';
        move[player->y][player->x] = p_is_on_storage(g) == 0 ? 'O' : ' ';
        player->y = player->y;
        player->x += 1;
    } else if (move[player->y][player->x + 1] == 'X'
            && (move[player->y][player->x + 2] == 'O'
            || move[player->y][player->x + 2] == ' ')) {
        move[player->y][player->x + 2] = 'X';
        move[player->y][player->x + 1] = 'P';
        move[player->y][player->x] = p_is_on_storage(g) == 0 ? 'O' : ' ';
        player->y = player->y;
        player->x += 1;
    }
}

void player_left(game_t *g, char **move, player_t *player)
{
    if (move[player->y][player->x - 1] == ' '
            || move[player->y][player->x - 1] == 'O') {
        move[player->y][player->x - 1] = 'P';
        move[player->y][player->x] = p_is_on_storage(g) == 0 ? 'O' : ' ';
        player->y = player->y;
        player->x -= 1;
    } else if (move[player->y][player->x - 1] == 'X'
            && (move[player->y][player->x - 2] == 'O'
            || move[player->y][player->x - 2] == ' ')) {
        move[player->y][player->x - 2] = 'X';
        move[player->y][player->x - 1] = 'P';
        move[player->y][player->x] = p_is_on_storage(g) == 0 ? 'O' : ' ';
        player->y = player->y;
        player->x -= 1;
    }
}
