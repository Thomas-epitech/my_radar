/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** game loop
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdio.h>
#include "radar.h"
#include "my.h"

int game_loop(game_t *game)
{
    sfClock *clock = sfClock_create();
    sfTime time_elapsed;
    sfEvent event;

    if (clock == NULL) {
        my_putstr("Failed to create clock\n");
        return -1;
    }
    while (sfRenderWindow_isOpen(game->window.render_window)) {
        time_elapsed = sfClock_restart(clock);
        game->clocks.delta_t = ((float)time_elapsed.microseconds / 1000000) *
            game->clocks.time_multiplier;
        game->clocks.total_t += game->clocks.delta_t;
        handle_events(game, &event);
        update_game_state(game, game->entities.planes);
        render_game(game);
    }
    sfClock_destroy(clock);
    return 0;
}
