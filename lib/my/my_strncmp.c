/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** task07
*/

#include <stdio.h>
#include <string.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while ((*s1 != '\0' || *s2 != '\0') && i < n) {
        if (*s1 ^ *s2)
            return *s1 ? 1 : -1;
        if (*s1 != *s2)
            return *s1 > *s2 ? 1 : -1;
        s1++;
        s2++;
        i++;
    }
    return 0;
}
