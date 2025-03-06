/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** task02
*/

#include "my.h"
char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    int size = my_strlen(src);

    for (i = 0; i < n && i < size; i++) {
        dest[i] = src[i];
    }
    dest[n] = '\0';
    return dest;
}
