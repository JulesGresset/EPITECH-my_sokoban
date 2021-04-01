/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** Gives length
*/

int my_strlen(char const *str)
{
    int counter = 0;

    while (*(str + counter) != '\0') {
        counter++;
    }
    return (counter);
}
