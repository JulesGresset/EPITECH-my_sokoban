/*
** EPITECH PROJECT, 2020
** my_put_cap_hex
** File description:
** Displays the number given as parameter
*/

#include "../../include/my.h"

int my_put_cap_hex(int nb)
{
    int res = 0;

    if (nb >= 16) {
        res = nb % 16;
        nb /= 16;
        my_put_hex(nb);

    } else if (nb > 0) {
        res = nb % 16;
        nb /= 16;
    }
    if (res > 9)
        my_putchar(res + 55);
    else
        my_putchar(res + '0');
}
