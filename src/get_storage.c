/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-nicolas1.nguyen
** File description:
** get_storage
*/

#include <my_sokoban.h>

storage_t *coord_storage(char c, int i, int j, storage_t *storage)
{
    if (c == 'O') {
        storage->x = j;
        storage->y = i;
    }
    return storage;
}

storage_t *get_storage(char **map)
{
    storage_t *storage = malloc(sizeof(storage_t));

    if (!storage)
        return NULL;
    storage->x = 0;
    storage->y = 0;
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            storage = coord_storage(map[i][j], i, j, storage);
        }
    }
    map[storage->y][storage->x] = ' ';
    return storage;
}

storage_t **get_all_storage(char **map, int count_o)
{
    storage_t **storages = malloc(sizeof(storage_t *) * count_o);

    if (!storages)
        return NULL;
    for (int i = 0; i < count_o; i++) {
        storages[i] = get_storage(map);
    }
    return storages;
}
