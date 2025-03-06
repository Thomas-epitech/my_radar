/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** get_plane_vertices
*/

#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "radar.h"

sfVector2f *get_plane_vertices(sfVector2f pos, float angle)
{
    sfVector2f *vertices = malloc(sizeof(sfVector2f) * PLANE_HITBOX_NB_VERTEX);
    float hb_half_size = (float)PLANE_HITBOX_SIZE / 2;
    int dx;
    int dy;

    if (vertices == NULL)
        return NULL;
    vertices[0] = (sfVector2f){pos.x - hb_half_size, pos.y - hb_half_size};
    vertices[1] = (sfVector2f){pos.x + hb_half_size, pos.y - hb_half_size};
    vertices[2] = (sfVector2f){pos.x + hb_half_size, pos.y + hb_half_size};
    vertices[3] = (sfVector2f){pos.x - hb_half_size, pos.y + hb_half_size};
    for (int i = 0; i < PLANE_HITBOX_NB_VERTEX; i++) {
        dx = vertices[i].x - pos.x;
        dy = vertices[i].y - pos.y;
        vertices[i] = (sfVector2f){
            pos.x + dx * cos(angle * DEG2RAD) - dy * sin(angle * DEG2RAD),
            pos.y + dx * sin(angle * DEG2RAD) + dy * cos(angle * DEG2RAD)};
    }
    return vertices;
}
