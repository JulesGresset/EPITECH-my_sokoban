/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** sokoban
*/

#include "sokoban.h"

void sokoban(void)
{
    pos pos;
    map map;

    init(&map);
    menu(&map, &pos);
}