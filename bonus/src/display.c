/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** display
*/

#include "sokoban.h"

void display_help(void)
{
    my_printf("USAGE\n    ./my_sokoban map\n");
    my_printf("DESCRIPTION\n    ");
    my_printf("map  file representing thr warehouse map, containing '#' for");
    my_printf(" walls,\n         'P' for the player, 'X' for boxes and");
    my_printf("'O' for storage locations.\n");
    exit(0);
}

void display_map_next(map *map)
{
    int col = 0;
    int row = 0;

    getmaxyx(stdscr, row, col);
    for (int i = 0; i < map->nbrRow; i++) {
        for (int j = 0; j < my_strlen(map->map[i]); j++) {
            if (map->objMap[i][j] == 'O' &&
                map->map[i][j] != 'X' &&
                map->map[i][j] != 'P')
                    mvprintw(row / 2 - map->nbrRow / 2 + i,
                col / 2 - map->maxNbrCol / 2 + j, "O");
        }
    }
}

void display_map(map *map)
{
    int i = 0;
    int row;
    int col;
    char *resize = "Too small!";

    getmaxyx(stdscr, row, col);
    if (row < map->nbrRow || col < map->maxNbrCol) {
        mvprintw(row / 2, col / 2 - my_strlen(resize), resize);
        return;
    }
    for (; i < map->nbrRow; i++) {
        mvprintw(row / 2 - map->nbrRow / 2 + i,
                col / 2 - map->maxNbrCol / 2, "%s", map->map[i]);
    }
    display_map_next(map);
}