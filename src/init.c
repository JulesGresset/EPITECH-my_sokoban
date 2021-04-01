/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** init
*/

#include "sokoban.h"

void init(void)
{
    initscr();
    noecho();
    keypad(stdscr, true);
}