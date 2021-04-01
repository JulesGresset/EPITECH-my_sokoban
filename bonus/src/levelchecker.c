/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** levelchecker
*/

#include "sokoban.h"

void levelchecker(map *map, pos *pos)
{
    if (map->level == 1)
        loop(map, pos, "map/level1.txt");
    if (map->level == 2)
        loop(map, pos, "map/level2.txt");
}