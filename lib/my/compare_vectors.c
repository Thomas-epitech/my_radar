/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** compare vectors
*/

#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <math.h>
#include "my.h"

bool compare_vectors(sfVector2f vec1, sfVector2f vec2, float epsilon)
{
    bool x_equal;
    bool y_equal;

    if (epsilon < 1)
        epsilon = 1;
    x_equal = fabs(vec1.x - vec2.x) < epsilon;
    y_equal = fabs(vec1.y - vec2.y) < epsilon;
    return x_equal && y_equal;
}
