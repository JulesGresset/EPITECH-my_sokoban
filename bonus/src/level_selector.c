/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** level_selector
*/

#include "sokoban.h"

void level_loader(int highlight, char **choices, map *map, pos *pos)
{
    if (choices[highlight] == choices[0]) {
        map->level = 1;
        levelchecker(map, pos);
    }
    if (choices[highlight] == choices[1]) {
        map->level = 2;
        levelchecker(map, pos);
    }
    if (choices[highlight] == choices[2]) {
        menu(map, pos);
    }
}

void level_selector(map *map, pos *pos)
{
    char *choices[3] = {"1", "2", "<Return to menu"};
    int key;
    int highlight = 0;

    clear();
    box(stdscr, 0, 0);
    refresh();
    mvwprintw(stdscr, 1, 1, "LEVEL SELECTOR");
    while (key != 10) {
        for (int i = 0; i < 3; i++) {
            if (i == highlight)
                wattron(stdscr, A_REVERSE);
            mvwprintw(stdscr, i + 2, 1, choices[i]);
            wattroff(stdscr, A_REVERSE);
        }
        key = wgetch(stdscr);
        highlight = arrow_handler(key, highlight);
    }
    level_loader(highlight, choices, map, pos);
}