/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** win_detection
*/

#include "sokoban.h"

void win_detection(map *map)
{
    int i;
    int j;
    int boxs = 0;
    int winBoxs = 0;

    for (i = 0; i < map->nbrRow; i++) {
        for (j = 0; j < my_strlen(map->map[i]); j++) {
            if (map->map[i][j] == 'X')
                boxs++;
            if (map->map[i][j] == 'X' && map->objMap[i][j] == 'O')
                winBoxs++;
        }
    }
    if (boxs == winBoxs) {
        endwin();
        exit(0);
    }
}