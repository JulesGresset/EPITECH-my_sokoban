/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** mouvment
*/

#include "sokoban.h"

void mvm_up(pos *pos, map *map)
{
    if (map->map[pos->yLoc - 1][pos->xLoc] == ' ' ||
        map->map[pos->yLoc - 1][pos->xLoc] == 'O')
        pos->yLoc--;
    else if (map->map[pos->yLoc - 1][pos->xLoc] == 'X' &&
            map->map[pos->yLoc - 2][pos->xLoc] != '#' &&
            map->map[pos->yLoc - 2][pos->xLoc] != 'X') {
        map->map[pos->yLoc - 2][pos->xLoc] = 'X';
        pos->yLoc--;
    }
}

void mvm_down(pos *pos, map *map)
{
    if (map->map[pos->yLoc + 1][pos->xLoc] == ' ' ||
        map->map[pos->yLoc + 1][pos->xLoc] == 'O')
        pos->yLoc++;
    else if (map->map[pos->yLoc + 1][pos->xLoc] == 'X' &&
            map->map[pos->yLoc + 2][pos->xLoc] != '#' &&
            map->map[pos->yLoc + 2][pos->xLoc] != 'X') {
        map->map[pos->yLoc + 2][pos->xLoc] = 'X';
        pos->yLoc++;
    }
}

void mvm_left(pos *pos, map *map)
{
    if (map->map[pos->yLoc][pos->xLoc - 1] == ' ' ||
        map->map[pos->yLoc][pos->xLoc - 1] == 'O')
        pos->xLoc--;
    else if (map->map[pos->yLoc][pos->xLoc - 1] == 'X' &&
            map->map[pos->yLoc][pos->xLoc - 2] != '#' &&
            map->map[pos->yLoc][pos->xLoc - 2] != 'X') {
        map->map[pos->yLoc][pos->xLoc - 2] = 'X';
        pos->xLoc--;
    }
}

void mvm_right(pos *pos, map *map)
{
    if (map->map[pos->yLoc][pos->xLoc + 1] == ' ' ||
        map->map[pos->yLoc][pos->xLoc + 1] == 'O')
        pos->xLoc++;
    else if (map->map[pos->yLoc][pos->xLoc + 1] == 'X' &&
            map->map[pos->yLoc][pos->xLoc + 2] != '#' &&
            map->map[pos->yLoc][pos->xLoc + 2] != 'X') {
        map->map[pos->yLoc][pos->xLoc + 2] = 'X';
        pos->xLoc++;
    }
}

void mouvment(int key, pos *pos, map *map)
{
    map->map[pos->yLoc][pos->xLoc] = ' ';
    if (key == KEY_RIGHT)
        mvm_right(pos, map);
    if (key == KEY_DOWN)
        mvm_down(pos, map);
    if (key == KEY_UP)
        mvm_up(pos, map);
    if (key == KEY_LEFT)
        mvm_left(pos, map);
    map->map[pos->yLoc][pos->xLoc] = 'P';
}