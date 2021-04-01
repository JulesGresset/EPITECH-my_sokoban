/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** loose_detection
*/

#include "sokoban.h"

void loose_detection(map *map)
{
    int boxs = 0;
    int stuckedBoxs = 0;

    for (int i = 0; i < map->nbrRow; i++) {
        for (int j = 0; j < my_strlen(map->map[i]); j++) {
            if (map->map[i][j] == 'X')
                boxs++;
            if (map->map[i][j] == 'X' &&
            ((map->map[i - 1][j] == '#' && map->map[i][j - 1] == '#') ||
            (map->map[i - 1][j] == '#' && map->map[i][j + 1] == '#') ||
            (map->map[i + 1][j] == '#' && map->map[i][j - 1] == '#') ||
            (map->map[i + 1][j] == '#' && map->map[i][j + 1] == '#')) &&
            map->objMap[i][j] != 'O')
                stuckedBoxs++;
        }
    }
    if (boxs == stuckedBoxs) {
        endwin();
        exit(1);
    }
}