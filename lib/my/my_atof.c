/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** my atof
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "my.h"

static int get_whole_part(char *str)
{
    int nb_digit = 0;
    int result = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '.')
            break;
        nb_digit++;
    }
    for (int i = 0; i < nb_digit; i++)
        result += (str[i] - 48) * pow(10, nb_digit - i - 1);
    return result;
}

static float get_fractional_part(char *str)
{
    int nb_digit = 0;
    bool fp_flag = false;
    int fp_index;
    float result = 0.0f;

    for (int i = 0; str[i]; i++) {
        if (fp_flag)
            nb_digit++;
        if (str[i] == '.') {
            fp_flag = true;
            fp_index = i;
        }
    }
    for (int i = fp_index + 1; i < nb_digit + fp_index + 1; i++)
        result += (str[i] - 48) * pow(10, fp_index - i);
    return result;
}

float my_atof(char *str)
{
    float result = 0;

    if (!str_is_float(str))
        return -1;
    result += get_whole_part(str);
    result += get_fractional_part(str);
    return result;
}
