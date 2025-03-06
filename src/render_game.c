/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** render window
*/

#include "radar.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>


static void render_grid(sfRenderWindow *render_window, grid_t *grid,
    sfRectangleShape *grid_square)
{
    if (grid->subgrids != NULL) {
        for (int i = 0; i < NB_SUBGRIDS; i++)
            render_grid(render_window, &grid->subgrids[i], grid_square);
        return;
    }
    if (grid->width == WINDOW_WIDTH && grid->height == WINDOW_HEIGHT)
        return;
    sfRectangleShape_setSize(grid_square,
        (sfVector2f){grid->width, grid->height});
    sfRectangleShape_setPosition(grid_square, grid->pos);
    sfRenderWindow_drawRectangleShape(render_window, grid_square, NULL);
}

static void render_planes(game_t *game)
{
    plane_t **planes = game->entities.planes;
    sfRectangleShape *hitbox = game->shapes.plane_hitbox;
    sfSprite *plane_sprite = game->ressources.sprites[1];
    sfRenderWindow *render_window = game->window.render_window;

    for (int i = 0; planes[i]; i++) {
        if (!planes[i]->is_flying)
            continue;
        if (game->display_options.sprites) {
            sfSprite_setRotation(plane_sprite, planes[i]->tilt_angle);
            sfSprite_setPosition(plane_sprite, planes[i]->curr_pos);
            sfRenderWindow_drawSprite(render_window, plane_sprite, NULL);
        }
        if (game->display_options.hitboxes) {
            sfRectangleShape_setRotation(hitbox, planes[i]->tilt_angle);
            sfRectangleShape_setPosition(hitbox, planes[i]->curr_pos);
            sfRenderWindow_drawRectangleShape(render_window, hitbox, NULL);
        }
    }
}

static void render_tower_sprites(sfRenderWindow *render_window,
    tower_t **towers, sfSprite *tower_sprite)
{
    for (int i = 0; towers[i]; i++) {
        sfSprite_setPosition(tower_sprite, towers[i]->pos);
        sfRenderWindow_drawSprite(render_window, tower_sprite, NULL);
    }
}

static void render_tower_areas(sfRenderWindow *render_window, tower_t **towers,
    sfCircleShape *tower_area)
{
    for (int i = 0; towers[i]; i++) {
        sfCircleShape_setOrigin(tower_area, (sfVector2f){towers[i]->radius,
            towers[i]->radius});
        sfCircleShape_setRadius(tower_area, towers[i]->radius);
        sfCircleShape_setPosition(tower_area, towers[i]->pos);
        sfRenderWindow_drawCircleShape(render_window, tower_area, NULL);
    }
}

static void render_towers(game_t *game)
{
    tower_t **towers = game->entities.towers;
    sfCircleShape *area = game->shapes.tower_area;
    sfSprite *tower_sprite = game->ressources.sprites[2];
    sfRenderWindow *render_window = game->window.render_window;

    if (game->display_options.sprites)
        render_tower_sprites(render_window, towers, tower_sprite);
    if (game->display_options.hitboxes)
        render_tower_areas(render_window, towers, area);
}

static void render_texts(sfRenderWindow *render_window, texts_t *texts)
{
    for (int i = 0; i < NB_TEXTS; i++)
        sfRenderWindow_drawText(render_window, texts->texts[i], NULL);
}

void render_game(game_t *game)
{
    sfRenderWindow *render_window = game->window.render_window;
    entities_t *entities = &game->entities;

    sfRenderWindow_clear(render_window, sfBlack);
    sfRenderWindow_drawSprite(render_window, game->ressources.sprites[0],
        NULL);
    if (entities->towers != NULL)
        render_towers(game);
    if (entities->planes != NULL)
        render_planes(game);
    render_texts(render_window, &game->texts);
    if (game->display_options.grid)
        render_grid(render_window, &game->grid, game->shapes.grid_square);
    sfRenderWindow_display(render_window);
}
