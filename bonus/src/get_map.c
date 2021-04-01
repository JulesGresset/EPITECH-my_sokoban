/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** get_map
*/

#include "sokoban.h"

char *open_map(char *path)
{
    int fd = 0;
    int rd = 0;
    char *buffer = malloc(sizeof(char) * 10000);

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        my_printf("Error while opening file\n");
        exit(84);
    }
    rd = read(fd, buffer, 10000);
    if (rd == -1) {
        my_printf("Error while reading file\n");
        exit(84);
    }
    close(fd);
    return buffer;
}

void get_row(map *map, char *buffer)
{
    int i;

    map->nbrRow = 1;
    for (i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n' || buffer[i] == '\0')
            map->nbrRow++;
    }
}

void get_col(map *map, char *buffer, int pos)
{
    map->nbrCol = 0;
    for (; buffer[pos] != '\n' && buffer[pos] != '\0'; pos++) {
        map->nbrCol++;
    }
    if (map->nbrCol > map->maxNbrCol)
        map->maxNbrCol = map->nbrCol;
}

void get_player_pos(map *map, pos *pos)
{
    int i;
    int j;

    for (i = 0; i < map->nbrRow; i++) {
        for (j = 0; j < my_strlen(map->map[i]) ; j++) {
            if (map->map[i][j] == 'P') {
                pos->xLoc = j;
                pos->yLoc = i;
                return;
            }
        }
    }
    my_printf("No player starting pos found\n");
    exit(84);
}

void get_map(map *map, pos *pos, char *path)
{
    int k = 0;
    char *buffer = open_map(path);
    map->maxNbrCol = 0;

    get_row(map, buffer);
    map->map = malloc(sizeof(char *) * map->nbrRow);
    map->objMap = malloc(sizeof(char *) * map->nbrRow);
    for (int i = 0; i < map->nbrRow; i++, k++) {
        get_col(map, buffer, k);
        map->map[i] = malloc(sizeof(char) * (map->nbrCol + 1));
        map->objMap[i] = malloc(sizeof(char) * (map->nbrCol + 1));
        for (int j = 0; j < map->nbrCol; j++, k++) {
            map->map[i][j] = buffer[k];
            map->objMap[i][j] = buffer[k];
            map->map[i][j + 1] = '\0';
            map->objMap[i][j + 1] = '\0';
        }
    }
    get_player_pos(map, pos);
}