/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Function that displays one by one the characters of a string
*/

#include <unistd.h>
#include "../../include/my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
