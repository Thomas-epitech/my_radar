/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** task03
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);

    for (int i = 0; src[i] != '\0' && i < nb; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + my_strlen(src)] = '\0';
    return dest;
}
