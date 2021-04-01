/*
** EPITECH PROJECT, 2021
** my_concate
** File description:
** my_concate
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strcat(char *p, char *c)
{
    char *res = malloc(sizeof(char) * (my_strlen(p) + my_strlen(c)));
    int i, j = 0;

    for (i = 0; i < my_strlen(p); i++) {
        res[i] = p[j];
        j++;
    }
    for (j = 0; i <= my_strlen(c) + my_strlen(p); i++) {
        res[i] = c[j];
        j++;
    }
    i++;
    res[i] = '\0';
    return res;
}