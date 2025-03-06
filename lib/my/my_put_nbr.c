/*
** EPITECH PROJECT, 2024
** my_put_number.c
** File description:
** task07
*/

#include "my.h"

int digit_counter(int nb)
{
    int i = 0;

    if (nb == 0) {
        return 1;
    }
    while (nb != 0) {
        nb /= 10;
        i++;
    }
    return i;
}

int my_put_nbr(int nb)
{
    int i;

    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar('2');
            nb = 147483648;
        } else {
            nb *= -1;
        }
    }
    i = digit_counter(nb);
    while (i > 0) {
        my_putchar((nb / (my_compute_power_rec(10, i - 1)) + 48));
        nb = nb % my_compute_power_rec(10, i - 1);
        i--;
    }
    return 0;
}
