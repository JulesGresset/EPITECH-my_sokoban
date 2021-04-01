/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** sokoban
*/

#include "sokoban.h"

void sokoban(int argc, char **argv)
{
    pos pos;
    map map;

    get_map(&map, &pos, argv[1]);
    errors_handling(&map);
    init();
    loop(&map, &pos, argv);
}