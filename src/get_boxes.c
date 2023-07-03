/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-nicolas1.nguyen
** File description:
** get_boxes
*/

#include <my_sokoban.h>

boxes_t *coord_boxes(char c, int i, int j, boxes_t *boxes)
{
    if (c == 'X') {
        boxes->x = j;
        boxes->y = i;
    }
    return boxes;
}

boxes_t *get_boxes(char **map)
{
    boxes_t *boxes = malloc(sizeof(boxes_t));

    if (!boxes)
        return NULL;
    boxes->x = 0;
    boxes->y = 0;
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            boxes = coord_boxes(map[i][j], i, j, boxes);
        }
    }
    map[boxes->y][boxes->x] = ' ';
    return boxes;
}

boxes_t **get_all_boxes(char **map, int count_x)
{
    boxes_t **boxes = malloc(sizeof(boxes_t *) * count_x);

    if (!boxes)
        return NULL;
    for (int i = 0; i < count_x; i++) {
        boxes[i] = get_boxes(map);
    }
    return boxes;
}
