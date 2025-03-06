/*
** EPITECH PROJECT, 2024
** radar
** File description:
** main
*/

#include "radar.h"

int main(int argc, char **argv)
{
    game_t game;
    int init_return = initialize_data(argc, argv, &game);

    if (init_return == 0)
        init_return = game_loop(&game);
    if (init_return == 1) {
        print_help_message();
        return 0;
    }
    free_data(&game);
    if (init_return == -1)
        return 84;
    return 0;
}
