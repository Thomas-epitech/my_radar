/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** get vector normalized
*/

#include <SFML/System/Vector2.h>
#include <math.h>
#include <stdio.h>

sfVector2f get_vector_normalized(sfVector2f vec)
{
    float magnitude = sqrt(vec.x * vec.x + vec.y * vec.y);

    return (sfVector2f){vec.x / magnitude, vec.y / magnitude};
}
