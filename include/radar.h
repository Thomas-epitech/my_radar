/*
** EPITECH PROJECT, 2024
** radar
** File description:
** header
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <math.h>

#ifndef RADAR_H
    #define RADAR_H
    #define NB_AIRPLANE_ARGS 7
    #define NB_TOWER_ARGS 4
    #define NB_TEXTURES 3
    #define NB_SPRITES 3
    #define NB_TEXTS 2
    #define NB_SUBGRIDS 4

    #define PLANE_SPRITE_WIDTH 20
    #define PLANE_SPRITE_HEIGHT 20
    #define PLANE_HITBOX_SIZE 20
    #define PLANE_HITBOX_NB_VERTEX 4

    #define TOWER_SPRITE_WIDTH 50
    #define TOWER_SPRITE_HEIGHT 50

    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080

    #define DEG2RAD M_PI / 180
    #define RAD2DEG 180 / M_PI

    #define MAX_PLANE_PER_GRID_SQUARE 100

typedef struct plane {
    sfVector2f dep_pos;
    sfVector2f arr_pos;
    sfVector2f curr_pos;
    sfVector2f direction;
    float speed;
    float delay;
    bool is_flying;
    float tilt_angle;
    sfVector2f *vertices;
} plane_t;

typedef struct {
    sfVector2f pos;
    int radius;
} tower_t;

typedef struct {
    float delta_t;
    float total_t;
    float time_multiplier;
} clocks_t;

typedef struct {
    plane_t **planes;
    tower_t **towers;
} entities_t;

typedef struct {
    sfRenderWindow *render_window;
    sfVideoMode video_mode;
} window_t;

typedef struct {
    sfTexture **textures;
    sfSprite **sprites;
} ressources_t;

typedef struct {
    sfFont *font;
    sfText **texts;
} texts_t;

typedef struct grid {
    sfVector2f pos;
    int width;
    int height;
    struct grid *subgrids;
    plane_t **planes;
    int nb_planes;
} grid_t;

typedef struct {
    bool sprites;
    bool hitboxes;
    bool grid;
} display_options_t;

typedef struct {
    sfRectangleShape *plane_hitbox;
    sfCircleShape *tower_area;
    sfRectangleShape *grid_square;
} shapes_t;

typedef struct {
    entities_t entities;
    clocks_t clocks;
    window_t window;
    ressources_t ressources;
    texts_t texts;
    grid_t grid;
    display_options_t display_options;
    shapes_t shapes;
} game_t;

int get_script_info(int, char **, entities_t *);
int initialize_data(int, char **, game_t *);
void free_data(game_t *);
int game_loop(game_t *);
void handle_events(game_t *, sfEvent *);
void update_game_state(game_t *, plane_t **);
sfVector2f *get_plane_vertices(sfVector2f pos, float);
void update_grid(grid_t *, plane_t **, tower_t **, int);
void render_game(game_t *);
void free_grid(grid_t *);
void check_collisions(grid_t *);
int get_nb_planes(plane_t **);
bool plane_is_near_tower(plane_t *, tower_t **);
void print_help_message(void);
#endif
