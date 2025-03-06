/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** task02
*/

#include "my.h"

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return 0;
}
