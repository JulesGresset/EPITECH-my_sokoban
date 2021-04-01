/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** loop
*/

#include "sokoban.h"

void loop(map *map, pos *pos, char **argv)
{
    int key = -1;

    while (key != ' ') {
        mouvment(key, pos, map);
        display_map(map);
        refresh();
        win_detection(map);
        loose_detection(map);
        key = getch();
        clear();
    }
    sokoban(2, argv);
}