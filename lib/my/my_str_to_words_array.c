/*
** EPITECH PROJECT, 2021
** my_str_to_words_array
** File description:
** Convert a str to an array
*/

#include "../../include/my.h"
#include <stdlib.h>

int str_to_word_array_next(int i, char *str)
{
    for (; str[i + 1] == ' ' || (str[i + 1] == '\\'
            && str[i + 2] == 't'); i++) {
        if (str[i + 1] == '\\' && str[i + 2] == 't')
            i++;
    }
    return i;
}

char **my_str_to_words_array(char *str)
{
    char **res = malloc(sizeof(char *) * (my_strlen(str) + 1));
    int i = 0, j = 0, n = 0;

    str = my_strcat(str, " ");
    res[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (i = 0; str[i + 1] != '\0'; i++) {
        if (str[i] != ' ' && !(str[i] == '\\' && str[i] == 't')
            && str[i + 1] != '\0') {
            res[n][j] = str[i];
            j++;
        } else {
            res[n][j] = '\0';
            n++;
            res[n] = malloc(sizeof(char) * (my_strlen(str) + 1));
            j = 0;
            i = str_to_word_array_next(i, str);
        }
    }
    return res;
}