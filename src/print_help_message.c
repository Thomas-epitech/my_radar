/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** print help message
*/

#include "my.h"

void print_help_message(void)
{
    my_putstr("Air traffic simulation panel\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_radar [OPTIONS] script_path\n");
    my_putstr(" script_path:\tThe path to the script file.\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -h\t\tprint the usage and quit.\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" \'L\' key\ttoggle display of hitboxes and areas.\n");
    my_putstr(" \'S\' key\ttoggle display of sprites.\n");
    my_putstr(" \'G\' key\ttoggle display of comparaison grid.\n");
    my_putstr(" [SPACE] key\tspeed up simulation.\n");
    my_putstr(" [ESC] key\tpause simulation.\n");
    my_putstr("        _                _\n");
    my_putstr("      -=\\`\\            /`/=-\n");
    my_putstr("  |\\ ____\\_\\_  \\|/  __/_/____ /|\n");
    my_putstr("-=\\ `\"\"\"\"\"\"\" \"`)ж(`\" \"\"\"\"\"\"\"\"` /=-\n");
    my_putstr("   `~~~~~/ /~~`/|\\`~~\\ \\~~~~~`\n");
    my_putstr("     -==/ /           \\ \\==-\n");
    my_putstr("       '-'             '-'\n");
}
