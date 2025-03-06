/*
** EPITECH PROJECT, 2024
** radar
** File description:
** get script info function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "radar.h"
#include "my.h"

static int is_valid_line(char **line)
{
    int nb_line_values = 0;

    for (; line[nb_line_values]; nb_line_values++);
    if (nb_line_values == 0)
        return -1;
    if ((!my_strcmp(line[0], "A") && nb_line_values != NB_AIRPLANE_ARGS) ||
        (!my_strcmp(line[0], "T") && nb_line_values != NB_TOWER_ARGS) ||
        (my_strcmp(line[0], "T") && my_strcmp(line[0], "A")))
        return -1;
    for (int i = 1; line[i]; i++) {
        if (!str_is_float(line[i]))
            return -1;
    }
    return 0;
}

static void count_elts(char *file_path, int counters[2])
{
    FILE *file = fopen(file_path, "r");
    char *buffer = NULL;
    size_t buff_size = 0;

    while (getline(&buffer, &buff_size, file) != -1) {
        if (buffer == NULL)
            break;
        if (buffer[0] == 'A')
            counters[0]++;
        if (buffer[0] == 'T')
            counters[1]++;
    }
    free(buffer);
    fclose(file);
}

static sfVector2f get_velocity_vector(sfVector2f dep_pos, sfVector2f arr_pos)
{
    int x_distance = arr_pos.x - dep_pos.x;
    int y_distance = arr_pos.y - dep_pos.y;
    int max_distance = MAX(ABS(x_distance), ABS(y_distance));

    return (sfVector2f){(float)x_distance / max_distance,
        (float)y_distance / max_distance};
}

static plane_t *create_plane(char **line_array)
{
    plane_t *plane = malloc(sizeof(plane_t));

    if (plane == NULL)
        return NULL;
    plane->dep_pos = (sfVector2f){my_atof(line_array[1]),
        my_atof(line_array[2])};
    plane->curr_pos = plane->dep_pos;
    plane->arr_pos = (sfVector2f){my_atof(line_array[3]),
        my_atof(line_array[4])};
    plane->direction = get_velocity_vector(plane->curr_pos, plane->arr_pos);
    plane->speed = my_atof(line_array[5]);
    plane->delay = my_atof(line_array[6]);
    plane->is_flying = false;
    plane->tilt_angle =
        atan2(plane->direction.y, plane->direction.x) * RAD2DEG;
    plane->vertices = get_plane_vertices(plane->curr_pos, plane->tilt_angle);
    return plane;
}

static void add_plane(char **line_array, entities_t *entities, int nb_planes)
{
    static int new_index = 0;

    if (entities->planes == NULL) {
        entities->planes = malloc(sizeof(plane_t *) * (nb_planes + 1));
        if (entities->planes == NULL)
            return;
        for (int i = 0; i < nb_planes + 1; i++)
            entities->planes[i] = NULL;
    }
    entities->planes[new_index] = create_plane(line_array);
    entities->planes[new_index + 1] = NULL;
    new_index++;
}

static tower_t *create_tower(char **line_array)
{
    tower_t *new_tower = malloc(sizeof(tower_t));

    if (new_tower == NULL)
        return NULL;
    new_tower->pos = (sfVector2f){my_atof(line_array[1]),
        my_atof(line_array[2])};
    new_tower->radius = my_atof(line_array[3]);
    return new_tower;
}

static void add_tower(char **line_array, entities_t *entities, int nb_towers)
{
    if (entities->towers == NULL) {
        entities->towers = malloc(sizeof(tower_t *) * (nb_towers + 1));
        if (entities->towers == NULL)
            return;
        for (int i = 0; i < nb_towers + 1; i++)
            entities->towers[i] = NULL;
    }
    for (int new_idx = 0; new_idx < nb_towers; new_idx++)
        if (entities->towers[new_idx] == NULL) {
            entities->towers[new_idx] = create_tower(line_array);
            break;
        }
}

static int parse_script(entities_t *entities, FILE *script, int counters[2])
{
    char *buffer = NULL;
    size_t buff_size = 0;
    char **line_array;

    for (int i = 1; getline(&buffer, &buff_size, script) != -1; i++) {
        line_array = my_str_to_word_array(buffer);
        if (line_array == NULL || is_valid_line(line_array) != 0) {
            mini_printf("Invalid file (l.%d)\n", i);
            free_double_ptr((void **)line_array);
            free(buffer);
            return -1;
        }
        if (!my_strcmp(line_array[0], "A"))
            add_plane(line_array, entities, counters[0]);
        else
            add_tower(line_array, entities, counters[1]);
        free_double_ptr((void **)line_array);
    }
    free(buffer);
    return 0;
}

int get_script_info(int argc, char **argv, entities_t *game)
{
    FILE *script;
    int return_val;
    int counters[2] = {0, 0};

    if (argc != 2) {
        my_putstr("The program only takes 1 argument.\n");
        return -1;
    }
    if (my_strcmp(argv[1], "-h") == 0)
        return 1;
    script = fopen(argv[1], "r+");
    if (!script) {
        mini_printf("Unable to open \"%s\"\n", argv[1]);
        return -1;
    }
    count_elts(argv[1], counters);
    return_val = parse_script(game, script, counters);
    fclose(script);
    return return_val;
}
