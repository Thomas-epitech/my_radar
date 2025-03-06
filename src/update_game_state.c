/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** update game state
*/

#include <stdlib.h>
#include "radar.h"
#include "my.h"

static void update_plane_postition(plane_t *plane, float delta_t)
{
    sfVector2f velocity_vec;
    sfVector2f normalized_direction;
    int speed;

    if (!plane->is_flying)
        return;
    speed = plane->speed;
    normalized_direction = get_vector_normalized(plane->direction);
    velocity_vec = (sfVector2f){normalized_direction.x * speed * delta_t,
        normalized_direction.y * speed * delta_t};
    plane->curr_pos = (sfVector2f){
        plane->curr_pos.x + velocity_vec.x,
        plane->curr_pos.y + velocity_vec.y};
    for (int i = 0; i < PLANE_HITBOX_NB_VERTEX; i++) {
        plane->vertices[i].x += velocity_vec.x;
        plane->vertices[i].y += velocity_vec.y;
    }
}

static void update_plane_status(plane_t *plane, clocks_t *clocks)
{
    float epsilon = plane->speed * clocks->delta_t;

    if (compare_vectors(plane->dep_pos, plane->curr_pos, epsilon) &&
        plane->delay <= clocks->total_t && !plane->is_flying)
        plane->is_flying = true;
    if (compare_vectors(plane->arr_pos, plane->curr_pos, epsilon) &&
        plane->is_flying)
        plane->is_flying = false;
}

static char *time_to_str(int minutes, int seconds)
{
    char *final_str = malloc(sizeof(char) * 6);
    char *str_minutes = int_to_str(minutes);
    char *str_seconds = int_to_str(seconds);

    if (minutes > 9)
        my_strcpy(final_str, str_minutes);
    else {
        final_str[0] = '0';
        my_strcpy(final_str + 1, str_minutes);
    }
    final_str[2] = ':';
    if (seconds > 9)
        my_strcpy(final_str + 3, str_seconds);
    else {
        final_str[3] = '0';
        my_strcpy(final_str + 4, str_seconds);
    }
    free(str_minutes);
    free(str_seconds);
    return final_str;
}

static void update_timer_text(sfText *text, float total_t)
{
    int minutes = (int)total_t / 60;
    int seconds = (int)total_t % 60;
    char *result = time_to_str(minutes, seconds);

    sfText_setString(text, result);
    free(result);
}

static void update_fps_text(sfText *text, float delta_t)
{
    static int fps = 0;
    static float time_elapsed = 0;
    char *first_part;
    const char *second_part = " fps";
    char *final_str;

    fps++;
    time_elapsed += delta_t;
    if (time_elapsed >= 1) {
        first_part = int_to_str(fps);
        final_str = malloc(sizeof(char) *
            (my_strlen(first_part) + my_strlen(second_part) + 1));
        my_strcpy(final_str, first_part);
        my_strcpy(final_str + my_strlen(first_part), second_part);
        sfText_setString(text, final_str);
        free(first_part);
        free(final_str);
        time_elapsed = 0;
        fps = 0;
    }
}

static void check_program_end(plane_t **planes, float total_t,
    sfRenderWindow *render_window)
{
    for (int i = 0; planes[i]; i++)
        if (planes[i]->is_flying || planes[i]->delay > total_t)
            return;
    sfRenderWindow_close(render_window);
}

void update_game_state(game_t *game, plane_t **planes)
{
    int nb_vulnerable_planes = 0;

    update_timer_text(game->texts.texts[0], game->clocks.total_t);
    update_fps_text(game->texts.texts[1], game->clocks.delta_t);
    if (planes == NULL)
        return;
    for (int i = 0; planes[i]; i++) {
        update_plane_status(planes[i], &game->clocks);
        update_plane_postition(planes[i], game->clocks.delta_t);
        if (planes[i]->is_flying &&
            !plane_is_near_tower(planes[i], game->entities.towers))
            nb_vulnerable_planes++;
    }
    free_grid(&game->grid);
    update_grid(&game->grid, planes, game->entities.towers,
        MAX(40, 5 * log2(nb_vulnerable_planes)));
    check_collisions(&game->grid);
    check_program_end(planes, game->clocks.total_t,
        game->window.render_window);
}
