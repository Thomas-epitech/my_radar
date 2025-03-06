/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** free data
*/

#include <stdlib.h>
#include "radar.h"
#include "my.h"

static void free_sprites(sfSprite **sprites)
{
    if (sprites == NULL)
        return;
    for (int i = 0; i < NB_SPRITES; i++)
        sfSprite_destroy(sprites[i]);
    free(sprites);
}

static void free_textures(sfTexture **textures)
{
    if (textures == NULL)
        return;
    for (int i = 0; i < NB_TEXTURES; i++)
        sfTexture_destroy(textures[i]);
    free(textures);
}

static void free_planes(plane_t **planes)
{
    if (planes == NULL)
        return;
    for (int i = 0; planes[i]; i++)
        free(planes[i]->vertices);
    free_double_ptr((void **)planes);
}

static void free_towers(tower_t **towers)
{
    if (towers == NULL)
        return;
    free_double_ptr((void **)towers);
}

static void free_texts(texts_t *texts)
{
    if (texts->texts != NULL) {
        for (int i = 0; i < NB_TEXTS; i++)
            sfText_destroy(texts->texts[i]);
        free(texts->texts);
    }
    if (texts->font != NULL)
        sfFont_destroy(texts->font);
}

static void destroy_window(sfRenderWindow *render_window)
{
    if (render_window == NULL)
        return;
    sfRenderWindow_destroy(render_window);
}

static void destroy_shapes(shapes_t *shapes)
{
    if (shapes->plane_hitbox != NULL)
        sfRectangleShape_destroy(shapes->plane_hitbox);
    if (shapes->tower_area != NULL)
        sfCircleShape_destroy(shapes->tower_area);
    if (shapes->grid_square != NULL)
        sfRectangleShape_destroy(shapes->grid_square);
}

void free_grid(grid_t *grid)
{
    if (grid == NULL)
        return;
    if (grid->subgrids != NULL)
        for (int i = 0; i < NB_SUBGRIDS; i++)
            free_grid(&grid->subgrids[i]);
    free(grid->planes);
    grid->planes = NULL;
    free(grid->subgrids);
    grid->subgrids = NULL;
    grid->nb_planes = 0;
}

void free_data(game_t *game)
{
    free_planes(game->entities.planes);
    free_towers(game->entities.towers);
    free_sprites(game->ressources.sprites);
    free_textures(game->ressources.textures);
    free_texts(&game->texts);
    destroy_window(game->window.render_window);
    destroy_shapes(&game->shapes);
    free_grid(&game->grid);
}
