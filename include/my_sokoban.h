/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-nicolas1.nguyen
** File description:
** my_sokoban
*/

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_

typedef struct map_s {
    char *buffer;
    char **map;
    char **move;
    char **storage;
    size_t size;
    int lines;
    int cols;
} map_t;

typedef struct player_s {
    int x;
    int y;
} player_t;

typedef struct storage_s {
    int x;
    int y;
} storage_t;

typedef struct boxes_s {
    int x;
    int y;
} boxes_t;

typedef struct game_s {
    player_t *p;
    map_t *m;
    storage_t **s;
    int count_x;
    int count_o;
    int count_victory;
} game_t;

int invalid_map(char *buffer);
int error(int ac, char **av);
int print_usage(int ac, char **av);
map_t *get_map(char *path);
storage_t **get_all_storage(char **map, int count_o);
boxes_t **get_all_boxes(char **map, int count_x);
game_t *initialise_game(char *path);
void game_loop(game_t *game);
void init_window(void);
void destroy(game_t *);
void destroy_all(game_t *);
void display_map(map_t *map);
void display_original_map(game_t *map);
player_t *coord_p(char c, int i, int j, player_t *player);
int p_is_on_storage(game_t *g);
int move_boxes(game_t *g);
void player_up(game_t *, char **map, player_t *);
void player_down(game_t *, char **map, player_t *);
void player_right(game_t *, char **map, player_t *);
void player_left(game_t *, char **map, player_t *);
void check_victory(game_t *g);
void check_loose(game_t *g);

#endif /* !MY_SOKOBAN_H_ */
