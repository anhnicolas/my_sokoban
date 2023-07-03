/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-nicolas1.nguyen
** File description:
** initialise
*/

#include <my_sokoban.h>
#include <my_utils.h>

player_t *coord_p(char c, int i, int j, player_t *player)
{
    if (c == 'P') {
        player->x = j;
        player->y = i;
    }
    return player;
}

int count_of_x(char c)
{
    int count_x = 0;

    if (c == 'X')
        count_x++;
    return count_x;
}

int count_of_o(char c)
{
    int count_o = 0;

    if (c == 'O')
        count_o++;
    return count_o;
}

player_t *init_player(char **map)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            player = coord_p(map[i][j], i, j, player);
        }
    }
    return player;
}

game_t *initialise_game(char *path)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->m = get_map(path);
    if (!game->m)
        return NULL;
    game->p = init_player(game->m->map);
    if (!game->p)
        return NULL;
    for (int i = 0; game->m->map[i] != NULL; i++) {
        for (int j = 0; game->m->map[i][j] != '\0'; j++) {
            game->count_o += count_of_o(game->m->map[i][j]);
            game->count_x += count_of_x(game->m->map[i][j]);
        }
    }
    game->s = get_all_storage(game->m->storage, game->count_o);
    return game;
}
