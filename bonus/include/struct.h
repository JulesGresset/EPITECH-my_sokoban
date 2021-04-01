/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-jules.gresset
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct {
    int xLoc;
    int yLoc;
} pos;

typedef struct {
    char **map;
    char **objMap;
    int nbrCol;
    int nbrRow;
    int maxNbrCol;
    int level;
} map;

#endif /* !STRUCT_H_ */
