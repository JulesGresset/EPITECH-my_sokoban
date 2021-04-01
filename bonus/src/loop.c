/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** loop
*/

#include "sokoban.h"

void loop(map *map, pos *pos, char *path)
{
    int key = -1;

    clear();
    get_map(map, pos, path);
    errors_handling(map);
    while (key != ' ') {
        mouvment(key, pos, map);
        display_map(map);
        refresh();
        win_detection(map, pos);
        loose_detection(map, pos);
        key = getch();
        clear();
    }
    levelchecker(map, pos);
}