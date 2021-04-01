/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "struct.h"

void init(void);

void sokoban(int argc, char **argv);

void mouvment(int key, pos *pos, map *map);

void get_map(map *map, pos *pos, char *path);

void display_map(map *map);

void win_detection(map *map);

void loose_detection(map *map);

void errors_handling(map *map);

void loop(map *map, pos *pos, char **argv);

void display_help(void);

void get_col(map *map, char *buffer, int pos);

void get_row(map *map, char *buffer);

#endif /* !PROTO_H_ */
