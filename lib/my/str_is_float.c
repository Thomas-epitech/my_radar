/*
** EPITECH PROJECT, 2025
** radar
** File description:
** str is float
*/

#include <stdbool.h>

bool str_is_float(char *str)
{
    bool fp_flag = false;

    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        if (str[i] == '.' && !fp_flag && i != 0) {
            fp_flag = true;
            continue;
        }
        return false;
    }
    return true;
}
