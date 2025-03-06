/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** int to str
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"

char *int_to_str(int nb)
{
    int nb_digit = my_intlen(nb);
    int last_char = nb_digit;
    char *result = malloc(sizeof(char) * nb_digit + 1);
    int result_idx = 0;
    int tmp;

    while (nb_digit > 0) {
        tmp = pow(10, nb_digit - 1);
        result[result_idx] = nb / tmp + 48;
        nb = nb % tmp;
        result_idx++;
        nb_digit--;
    }
    result[last_char] = '\0';
    return result;
}
