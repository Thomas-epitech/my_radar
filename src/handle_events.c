/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** handle events
*/

#include <stdio.h>
#include "radar.h"

static void handle_window_event(sfRenderWindow *render_window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(render_window);
}

static void handle_keyboard_events(display_options_t *options, sfEvent *event,
    float *time_multiplier)
{
    if (event->type != sfEvtKeyPressed)
        return;
    if (event->key.code == sfKeyS)
        options->sprites = !options->sprites;
    if (event->key.code == sfKeyL)
        options->hitboxes = !options->hitboxes;
    if (event->key.code == sfKeyG)
        options->grid = !options->grid;
    if (event->key.code == sfKeyEscape) {
        if (*time_multiplier != 0)
            *time_multiplier = 0;
        else
            *time_multiplier = 1;
    }
}

void handle_events(game_t *game, sfEvent *event)
{
    sfRenderWindow *render_window = game->window.render_window;
    float *time_multiplier = &game->clocks.time_multiplier;

    while (sfRenderWindow_pollEvent(render_window, event)) {
        handle_window_event(render_window, event);
        handle_keyboard_events(&game->display_options, event, time_multiplier);
    }
    if (*time_multiplier == 0)
        return;
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        *time_multiplier = 2.5;
    else
        *time_multiplier = 1;
}
