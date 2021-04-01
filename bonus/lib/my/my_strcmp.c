/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Compare two strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}