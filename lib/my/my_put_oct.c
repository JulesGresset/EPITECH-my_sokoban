/*
** EPITECH PROJECT, 2020
** my_put_oct
** File description:
** Displays the number given as parameter
*/

#include "../../include/my.h"

int my_put_oct(int nb)
{
    int res = 0;

    if (nb >= 8) {
        res = nb % 8;
        nb /= 8;
        my_put_oct(nb);

    } else if (nb > 0) {
        res = nb % 8;
        nb /= 8;
    }
    my_putchar(res + '0');
}
