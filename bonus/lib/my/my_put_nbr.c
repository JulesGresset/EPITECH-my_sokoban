/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Displays the number given as parameter
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb ==  -(__INT_MAX__) - 1) {
        my_putstr("-2147483648");
        return 1;
    }
    if (nb < 0) {
        my_putchar('-');
    nb *= -1;
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    my_putchar((nb % 10) + '0');
}
