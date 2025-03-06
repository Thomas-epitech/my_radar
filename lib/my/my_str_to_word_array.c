/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** task04
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int is_separator(char c)
{
    return c == ' ' || c == '\n' || c == '\0';
}

static int count_words(char const *str)
{
    int counter = 0;

    for (int i = 0; str[i]; i++)
        if (!is_separator(str[i]) && is_separator(str[i + 1]))
            counter++;
    return counter;
}

static int count_letters(char const *str, int *index)
{
    int counter = 0;
    int i = *index;

    while (counter == 0 || !is_separator(str[i])) {
        if (str[i] == '\n' || str[i] == '\0')
            break;
        if (!is_separator(str[i]))
            counter++;
        i++;
    }
    *index = i;
    return counter;
}

static int fill_array(char **dest, const char *str)
{
    int nb_letters;
    int tmp;
    int dest_idx = 0;

    for (int i = 0; str[i]; i++) {
        tmp = i;
        nb_letters = count_letters(str, &i);
        dest[dest_idx] = malloc(sizeof(char) * (nb_letters + 1));
        if (dest[dest_idx] == NULL)
            return -1;
        my_strncpy(dest[dest_idx], str + tmp, nb_letters);
        dest_idx++;
    }
    return 0;
}

char **my_str_to_word_array(char const *str)
{
    char **dest;

    if (str == NULL || count_words(str) == 0)
        return NULL;
    dest = malloc(sizeof(char *) * (count_words(str) + 1));
    if (dest == NULL)
        return NULL;
    if (fill_array(dest, str) == -1)
        return NULL;
    dest[count_words(str)] = NULL;
    return dest;
}
