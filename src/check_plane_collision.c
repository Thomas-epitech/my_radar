/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** check plane collision
*/

#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "radar.h"

static float *get_proj_intvl(sfVector2f axis, sfVector2f *vertices)
{
    float *interval = malloc(sizeof(float) * 2);
    float dot_product;

    if (interval == NULL)
        return NULL;
    dot_product = get_dot_product(vertices[0], axis);
    interval[0] = dot_product;
    interval[1] = dot_product;
    for (int i = 1; i < PLANE_HITBOX_NB_VERTEX; i++) {
        dot_product = get_dot_product(vertices[i], axis);
        if (dot_product < interval[0])
            interval[0] = dot_product;
        if (dot_product > interval[1])
            interval[1] = dot_product;
    }
    return interval;
}

static bool check_interval_intersection(float *intvl1, float *intvl2)
{
    return (intvl1[0] <= intvl2[1] && intvl1[1] >= intvl2[0]);
}

static bool is_projection_intersecting(plane_t *p1, plane_t *p2,
    sfVector2f axis)
{
    float *p1_proj_intvl = NULL;
    float *p2_proj_intvl = NULL;
    bool result = false;

    p1_proj_intvl = get_proj_intvl(axis, p1->vertices);
    p2_proj_intvl = get_proj_intvl(axis, p2->vertices);
    if (p1_proj_intvl != NULL && p2_proj_intvl != NULL)
        result = check_interval_intersection(p1_proj_intvl, p2_proj_intvl);
    free(p1_proj_intvl);
    free(p2_proj_intvl);
    return result;
}

static bool planes_are_colliding(plane_t *p1, plane_t *p2)
{
    sfVector2f separating_axis[] = {
        get_vector_normalized(p1->direction),
        get_vector_normalized(get_perpendicular_vector(p1->direction)),
        get_vector_normalized(p2->direction),
        get_vector_normalized(get_perpendicular_vector(p2->direction))};

    if (p1 == p2)
        return false;
    for (int i = 0; i < 4; i++)
        if (!is_projection_intersecting(p1, p2, separating_axis[i]))
            return false;
    return true;
}

static void handle_collision(plane_t *p1, plane_t *p2)
{
    if (planes_are_colliding(p1, p2) && p1->is_flying && p2->is_flying) {
        p1->is_flying = false;
        p2->is_flying = false;
    }
}

void check_collisions(grid_t *grid)
{
    if (grid == NULL || grid->planes == NULL)
        return;
    if (grid->subgrids != NULL) {
        for (int i = 0; i < NB_SUBGRIDS; i++)
            check_collisions(&grid->subgrids[i]);
        return;
    }
    for (int i = 0; grid->planes[i]; i++)
        for (int j = i + 1; grid->planes[j]; j++)
            handle_collision(grid->planes[i], grid->planes[j]);
}
