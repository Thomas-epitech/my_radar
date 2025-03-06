/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** get perpendicular vector
*/

#include <SFML/System/Vector2.h>

sfVector2f get_perpendicular_vector(sfVector2f vec)
{
    return (sfVector2f){- vec.y, vec.x};
}
