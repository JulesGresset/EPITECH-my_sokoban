/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** errors_handling
*/

#include "sokoban.h"

void errors_handling(map *map)
{
    int i;
    int j;

    for (i = 0; i < map->nbrRow; i++) {
        for (j = 0; j < my_strlen(map->map[i]); j++) {
            if (map->map[i][j] != '#' &&
                map->map[i][j] != ' ' &&
                map->map[i][j] != 'X' &&
                map->map[i][j] != 'O' &&
                map->map[i][j] != 'P' &&
                map->map[i][j] != '\n' &&
                map->map[i][j] != '\0') {
                my_printf("Incorrect character in map file found : ");
                my_printf("%c\n", map->map[i][j]);
                exit(84);
            }
        }
    }
}