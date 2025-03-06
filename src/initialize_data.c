/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** init radar
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "radar.h"
#include "my.h"

static void init_grid(grid_t *grid)
{
    grid->pos = (sfVector2f){0, 0};
    grid->width = WINDOW_WIDTH;
    grid->height = WINDOW_HEIGHT;
    grid->subgrids = NULL;
    grid->planes = NULL;
    grid->nb_planes = 0;
}

static void default_init(game_t *game)
{
    game->entities.planes = NULL;
    game->entities.towers = NULL;
    game->window.render_window = NULL;
    game->ressources.textures = NULL;
    game->ressources.sprites = NULL;
    game->texts.font = NULL;
    game->texts.texts = NULL;
    game->shapes.plane_hitbox = NULL;
    game->shapes.tower_area = NULL;
    game->shapes.grid_square = NULL;
    game->clocks.delta_t = 0;
    game->clocks.total_t = 0;
    game->clocks.time_multiplier = 1;
    game->display_options.sprites = true;
    game->display_options.hitboxes = true;
    game->display_options.grid = false;
    init_grid(&game->grid);
}

static int init_window(window_t *window)
{
    window->video_mode = (sfVideoMode){WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    window->render_window = sfRenderWindow_create(window->video_mode,
        "My Radar", sfResize | sfClose, NULL);
    if (window->render_window == NULL) {
        my_putstr("Unable to open window\n");
        return -1;
    }
    return 0;
}

static int init_textures(ressources_t *rsc)
{
    char *file_paths[] = {"ressources/images/background.png",
        "ressources/images/plane.png", "ressources/images/tower.png"};

    rsc->textures = malloc(sizeof(sfTexture *) * NB_TEXTURES);
    if (rsc->textures == NULL) {
        my_putstr("Unable to allocate memory for textures\n");
        return -1;
    }
    for (int i = 0; i < NB_TEXTURES; i++) {
        rsc->textures[i] = sfTexture_createFromFile(file_paths[i], NULL);
        if (rsc->textures[i] == NULL) {
            mini_printf("Unable to create texture from \"%s\"\n",
                file_paths[i]);
            return -1;
        }
    }
    return 0;
}

static int init_sprites(ressources_t *rsc)
{
    rsc->sprites = malloc(sizeof(sfSprite *) * NB_SPRITES);
    if (rsc->sprites == NULL) {
        my_putstr("Unable to allocate memory for sprites\n");
        return -1;
    }
    for (int i = 0; i < NB_SPRITES; i++) {
        rsc->sprites[i] = sfSprite_create();
        if (rsc->sprites[i] == NULL) {
            mini_printf("Unable to create sprite n°%i\n", i);
            return -1;
        }
        sfSprite_setTexture(rsc->sprites[i], rsc->textures[i], sfFalse);
    }
    sfSprite_setOrigin(rsc->sprites[1], (sfVector2f){(float)PLANE_SPRITE_WIDTH
        / 2, (float)PLANE_SPRITE_HEIGHT / 2});
    sfSprite_setOrigin(rsc->sprites[2], (sfVector2f){(float)TOWER_SPRITE_WIDTH
        / 2, (float)TOWER_SPRITE_HEIGHT / 2});
    return 0;
}

static int init_ressources(ressources_t *rsc)
{
    if (init_textures(rsc) == -1)
        return -1;
    if (init_sprites(rsc) == -1)
        return -1;
    return 0;
}

static sfText *create_txt(sfFont *font, sfVector2f position, int size,
    int text_index)
{
    sfText *new_text = sfText_create();
    char *original_texts[] = {"00:00", "0 fps"};

    if (new_text == NULL) {
        my_putstr("Couldn't create text\n");
        return NULL;
    }
    sfText_setFont(new_text, font);
    sfText_setCharacterSize(new_text, size);
    sfText_setPosition(new_text, position);
    sfText_setString(new_text, original_texts[text_index]);
    return new_text;
}

static int init_texts(texts_t *texts)
{
    int text_sze[] = {50, 30};
    sfVector2f text_pos[] = {
        (sfVector2f){1600, 10}, (sfVector2f){10, 10}};

    texts->texts = malloc(sizeof(sfText *) * NB_TEXTS);
    if (texts->texts == NULL) {
        my_putstr("Unable to allocate memory for texts\n");
        return -1;
    }
    texts->font = sfFont_createFromFile("ressources/fonts/font.ttf");
    if (texts->font == NULL) {
        my_putstr("Unable to load font from file\n");
        return -1;
    }
    for (int i = 0; i < NB_TEXTS; i++) {
        texts->texts[i] = create_txt(texts->font, text_pos[i], text_sze[i], i);
        if (texts->texts[i] == NULL)
            return -1;
    }
    return 0;
}

static int init_shapes(shapes_t *shapes)
{
    shapes->plane_hitbox = sfRectangleShape_create();
    shapes->tower_area = sfCircleShape_create();
    shapes->grid_square = sfRectangleShape_create();
    if (shapes->plane_hitbox == NULL || shapes->tower_area == NULL ||
        shapes->grid_square == NULL)
        return -1;
    sfRectangleShape_setSize(shapes->plane_hitbox,
        (sfVector2f){PLANE_HITBOX_SIZE, PLANE_HITBOX_SIZE});
    sfRectangleShape_setOrigin(shapes->plane_hitbox, (sfVector2f){
        (float)PLANE_HITBOX_SIZE / 2, (float)PLANE_HITBOX_SIZE / 2});
    sfRectangleShape_setFillColor(shapes->plane_hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(shapes->plane_hitbox, sfGreen);
    sfRectangleShape_setOutlineThickness(shapes->plane_hitbox, 1.0f);
    sfCircleShape_setFillColor(shapes->tower_area, sfTransparent);
    sfCircleShape_setOutlineColor(shapes->tower_area, sfBlue);
    sfCircleShape_setOutlineThickness(shapes->tower_area, 1.0f);
    sfRectangleShape_setFillColor(shapes->grid_square, sfTransparent);
    sfRectangleShape_setOutlineColor(shapes->grid_square, sfRed);
    sfRectangleShape_setOutlineThickness(shapes->grid_square, 1.0f);
    return 0;
}

int initialize_data(int argc, char **argv, game_t *game)
{
    int parsing_return;

    default_init(game);
    parsing_return = get_script_info(argc, argv, &game->entities);
    if (parsing_return == 1)
        return 1;
    if (parsing_return == -1 || init_window(&game->window) == -1 ||
        init_texts(&game->texts) == -1 ||
        init_ressources(&game->ressources) == -1 ||
        init_shapes(&game->shapes) == -1)
        return -1;
    return 0;
}
