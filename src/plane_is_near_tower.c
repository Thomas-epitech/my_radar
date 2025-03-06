/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** plane is near tower
*/

#include <stdbool.h>
#include "radar.h"

bool plane_is_near_tower(plane_t *plane, tower_t **towers)
{
    float x_dis;
    float y_dis;
    float distance_plane_tower;

    if (towers == NULL)
        return false;
    for (int i = 0; towers[i]; i++) {
        x_dis = plane->curr_pos.x - towers[i]->pos.x;
        y_dis = plane->curr_pos.y - towers[i]->pos.y;
        distance_plane_tower = sqrt(x_dis * x_dis + y_dis * y_dis);
        if (distance_plane_tower <= towers[i]->radius)
            return true;
    }
    return false;
}
