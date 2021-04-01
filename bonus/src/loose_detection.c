/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** loose_detection
*/

#include "sokoban.h"

void loose_screen(map *map, pos *pos)
{
    int row = 0;
    int col = 0;
    int key = -1;

    while (key != ' ' && key != 27) {
        clear();
        getmaxyx(stdscr, row, col);
        move(row / 2, col / 2 - (my_strlen("LEVEL FAILED") / 2));
        printw("LEVEL FAILED");
        move(row/2+2, col/2 - (my_strlen("Press SPACE to retry")/2));
        printw("Press SPACE to retry");
        move(row/2+3, col/2-(my_strlen("Press ESC to return to the menu")/2));
        printw("Press ESC to return to the menu");
        refresh();
        key = getch();
    }
    if (key == ' ') {
        levelchecker(map, pos);
    } else if (key == 27)
        menu(map, pos);
}

void loose_detection(map *map)
{
    int boxs = 0;
    int stuckedBoxs = 0;

    for (int i = 0; i < map->nbrRow; i++) {
        for (int j = 0; j < my_strlen(map->map[i]); j++) {
            if (map->map[i][j] == 'X')
                boxs++;
            if (map->map[i][j] == 'X' &&
            ((map->map[i - 1][j] == '#' && map->map[i][j - 1] == '#') ||
            (map->map[i - 1][j] == '#' && map->map[i][j + 1] == '#') ||
            (map->map[i + 1][j] == '#' && map->map[i][j - 1] == '#') ||
            (map->map[i + 1][j] == '#' && map->map[i][j + 1] == '#')) &&
            map->objMap[i][j] != 'O')
                stuckedBoxs++;
        }
    }
    if (boxs == stuckedBoxs) {
        endwin();
        exit(1);
    }
}