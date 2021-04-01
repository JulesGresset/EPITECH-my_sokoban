/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** menu
*/

#include "sokoban.h"

int arrow_handler(int key, int highlight)
{
    if (key == KEY_UP) {
        highlight--;
        if (highlight == -1)
            highlight = 0;
    }
    if (key == KEY_DOWN) {
        highlight++;
        if (highlight == 3)
            highlight = 2;
    }
    return highlight;
}

void menu_choices(int highlight, char **choices, map *map, pos *pos)
{
    if (choices[highlight] == choices[0]) {
        clear();
        levelchecker(map, pos);
    }
    if (choices[highlight] == choices[1]) {
        clear();
        level_selector(map, pos);
    }
    if (choices[highlight] == choices[2]) {
        clear();
        endwin();
        exit(0);
    }
}

void menu(map *map, pos *pos)
{
    char *choices[3] = {"Play", "Level selector", "Exit"};
    int key;
    int highlight = 0;

    clear();
    box(stdscr, 0, 0);
    refresh();
    mvwprintw(stdscr, 1, 1, "MY_SOKOBAN PROJECT");
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
    menu_choices(highlight, choices, map, pos);
}