/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** get dot product
*/

#include <SFML/System/Vector2.h>

float get_dot_product(sfVector2f vec1, sfVector2f vec2)
{
    return vec1.x * vec2.x + vec1.y * vec2.y;
}
