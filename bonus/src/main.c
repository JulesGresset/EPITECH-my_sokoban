/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** main
*/

#include "sokoban.h"

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        display_help();
    sokoban();
}