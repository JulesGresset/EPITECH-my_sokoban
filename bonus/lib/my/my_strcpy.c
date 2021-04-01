/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** Copies a string into another one
*/

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    return (dest);
}