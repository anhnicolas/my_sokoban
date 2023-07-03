/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-nicolas1.nguyen
** File description:
** get_map
*/

#include <my_sokoban.h>
#include <my_utils.h>

void read_file(int fd, char *buffer, size_t size)
{
    read(fd, buffer, size);
    buffer[size] = '\0';
}

int get_cols(char **map)
{
    int count = 0;
    int temp = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            count++;
        }
        if (count > temp)
            temp = count;
        count = 0;
    }
    return temp;
}

int get_lines(char *str, char separator)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator)
            count++;
    }
    return count;
}

size_t get_size_of_file(char *file)
{
    size_t size;
    struct stat st;

    if (stat(file, &st) != 0)
        return 0;
    size = st.st_size;
    return size;
}

map_t *get_map(char *path)
{
    int fd = open(path, O_RDONLY);
    map_t *map = malloc(sizeof(map_t));

    map->size = get_size_of_file(path);
    if (fd == -1 || map->size == 0)
        return NULL;
    map->buffer = malloc(sizeof(char) * map->size + 1);
    read_file(fd, map->buffer, map->size);
    close(fd);
    map->lines = get_lines(map->buffer, '\n');
    map->map = my_str_to_word_tab(map->buffer, '\n');
    map->move = my_str_to_word_tab(map->buffer, '\n');
    map->storage = my_str_to_word_tab(map->buffer, '\n');
    map->cols = get_cols(map->map);
    return map;
}
