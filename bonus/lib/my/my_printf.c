/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** Main file
*/

#include <stdarg.h>
#include "../../include/my.h"

int check_format_id(char *str, int i, va_list list)
{
    if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
        my_put_nbr(va_arg(list, int));
    if (str[i] == 'c')
        my_putchar(va_arg(list, char *));
    if (str[i] == 's')
        my_putstr(va_arg(list, char *));
    if (str[i] == 'o')
        my_put_oct(va_arg(list, int));
    if (str[i] == 'x')
        my_put_hex(va_arg(list, int));
    if (str[i] == 'X')
        my_put_cap_hex(va_arg(list, int));
    if (str[i] == 'f')
        my_put_float(va_arg(list, double));
    return 0;
}

int check_str(char *str, va_list list)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            if (str[i+1] == '%') {
                my_putchar('%');
                i++;
            } else {
                i++;
                check_format_id(str, i, list);
            }
        } else
            my_putchar(str[i]);
    }
    return 0;
}

void my_printf(char *str, ...)
{
    va_list list;

    va_start(list, str);
    check_str(str, list);
    va_end(list);
}