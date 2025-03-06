/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}
