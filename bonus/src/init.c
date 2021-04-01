/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** init
*/

#include "sokoban.h"

void init(map *map)
{
    initscr();
    noecho();
    keypad(stdscr, true);
    map->level = 1;
}