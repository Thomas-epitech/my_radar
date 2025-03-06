/*
** EPITECH PROJECT, 2024
** miniprintf
** File description:
** miniprintf function
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"

static int count_int_digit(int nb)
{
    int counter = 0;

    while (nb != 0) {
        counter++;
        nb = nb / 10;
    }
    return counter;
}

static int handle_format(const char next, va_list *args)
{
    int int_tmp;
    char *str_tmp;

    if (next == 'd' || next == 'i') {
        int_tmp = va_arg(*args, int);
        my_put_nbr(int_tmp);
        return count_int_digit(int_tmp);
    }
    if (next == 's') {
        str_tmp = va_arg(*args, char *);
        my_putstr(str_tmp);
        return my_strlen(str_tmp);
    }
    if (next == 'c') {
        my_putchar(va_arg(*args, int));
    }
    if (next == '%') {
        my_putchar('%');
    }
    return 1;
}

static int valid_format(const char n)
{
    return (n == 'd' || n == 'i' || n == '%' || n == 'c' || n == 's');
}

int check_error(const char *format)
{
    int count = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && !valid_format(format[i + 1]))
            return -1;
        if (format[i] == '%') {
            i++;
            count++;
        }
    }
    return count;
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int counter = 0;

    va_start(args, format);
    if (check_error(format) == -1) {
        write(2, "Invalid format identifier.\n", 28);
        return -1;
    }
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            counter += handle_format(format[i + 1], &args);
            i++;
        } else {
            my_putchar(format[i]);
            counter++;
        }
    }
    return counter;
}
