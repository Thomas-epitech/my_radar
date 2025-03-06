/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** update grid
*/

#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "radar.h"

int get_nb_planes(plane_t **planes)
{
    int counter = 0;

    if (planes == NULL)
        return 0;
    for (; planes[counter]; counter++);
    return counter;
}

static bool plane_in_grid(grid_t *grid, plane_t *plane, tower_t **towers)
{
    return (plane->is_flying &&
            plane->curr_pos.x >= grid->pos.x &&
            plane->curr_pos.x < grid->pos.x + grid->width &&
            plane->curr_pos.y >= grid->pos.y &&
            plane->curr_pos.y < grid->pos.y + grid->height &&
            !plane_is_near_tower(plane, towers));
}

static void allocate_grid_planes(grid_t *grid, plane_t **planes,
    tower_t **towers)
{
    int nb_planes = 0;

    for (int i = 0; planes[i]; i++)
        if (plane_in_grid(grid, planes[i], towers))
            nb_planes++;
    grid->planes = malloc(sizeof(plane_t *) * (nb_planes + 1));
    if (grid->planes == NULL)
        return;
    for (int i = 0; i < nb_planes + 1; i++)
        grid->planes[i] = NULL;
}

static void fill_grid_planes(grid_t *grid, plane_t **planes, tower_t **towers)
{
    if (grid->planes == NULL)
        allocate_grid_planes(grid, planes, towers);
    for (int i = 0; planes[i]; i++) {
        if (plane_in_grid(grid, planes[i], towers)) {
            grid->planes[grid->nb_planes] = planes[i];
            grid->nb_planes++;
        }
    }
}

static int init_subgrids(grid_t *grid)
{
    int half_grid_width = grid->width / 2;
    int half_grid_height = grid->height / 2;
    sfVector2f positions[] = {grid->pos,
        (sfVector2f){grid->pos.x + half_grid_width, grid->pos.y},
        (sfVector2f){grid->pos.x, grid->pos.y + half_grid_height},
        (sfVector2f){grid->pos.x + half_grid_width,
            grid->pos.y + half_grid_height}};

    grid->subgrids = malloc(sizeof(grid_t) * NB_SUBGRIDS);
    if (grid->subgrids == NULL)
        return -1;
    for (int i = 0; i < NB_SUBGRIDS; i++) {
        grid->subgrids[i].pos = positions[i];
        grid->subgrids[i].width = half_grid_width;
        grid->subgrids[i].height = half_grid_height;
        grid->subgrids[i].subgrids = NULL;
        grid->subgrids[i].planes = NULL;
        grid->subgrids[i].nb_planes = 0;
    }
    return 0;
}

void update_grid(grid_t *grid, plane_t **planes, tower_t **towers,
    int threshold)
{
    if (grid->planes == NULL)
        fill_grid_planes(grid, planes, towers);
    if (get_nb_planes(grid->planes) <= threshold)
        return;
    init_subgrids(grid);
    for (int i = 0; i < NB_SUBGRIDS; i++)
        update_grid(&grid->subgrids[i], grid->planes, towers, threshold);
}
