/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** win_detection
*/

#include "sokoban.h"

void win_screen(map *map, pos *pos)
{
    int row = 0;
    int col = 0;
    int key = -1;

    while (key != ' ' && key != 27) {
        clear();
        getmaxyx(stdscr, row, col);
        move(row / 2, col / 2 - (my_strlen("LEVEL COMPLETED") / 2));
        printw("LEVEL COMPLETED");
        move(row/2+2, col/2 - (my_strlen("Press SPACE for the next level")/2));
        printw("Press SPACE for the next level");
        move(row/2+3, col/2-(my_strlen("Press ESC to return to the menu")/2));
        printw("Press ESC to return to the menu");
        refresh();
        key = getch();
    }
    if (key == ' ') {
        map->level++;
        levelchecker(map, pos);
    } else if (key == 27)
        menu(map, pos);
}

void win_detection(map *map)
{
    int i;
    int j;
    int boxs = 0;
    int winBoxs = 0;

    for (i = 0; i < map->nbrRow; i++) {
        for (j = 0; j < my_strlen(map->map[i]); j++) {
            if (map->map[i][j] == 'X')
                boxs++;
            if (map->map[i][j] == 'X' && map->objMap[i][j] == 'O')
                winBoxs++;
        }
    }
    if (boxs == winBoxs) {
        endwin();
        exit(0);
    }
}