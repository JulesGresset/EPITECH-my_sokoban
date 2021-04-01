/*
** EPITECH PROJECT, 2020
** my_get_nbr
** File description:
** Get number from c har
*/

#include "../../include/my.h"

double my_getnbr(char *nb)
{
    double res = 0;
    int sign = 1;
    double coef = 10;

    if (nb[0] == '-') {
        sign = -1;
        nb[0] = '0';
    }
    while (*nb >= '0' && *nb <= '9') {
        res = res * 10 + (*nb - '0');
        (nb)++;
    }
    if (*nb == '.') {
        while (nb[1] >= '0' && nb[1] <= '9') {
            res = res + (nb[1] - '0') / coef;
            coef *= 10;
            (nb)++;
        }
    }
    return res * sign;
}