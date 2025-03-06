/*
** EPITECH PROJECT, 2024
** radar
** File description:
** free double pointer
*/

#include <stdlib.h>
#include "my.h"

void free_double_ptr(void **ptr)
{
    if (ptr == NULL)
        return;
    for (int i = 0; ptr[i]; i++)
        free(ptr[i]);
    free(ptr);
}
