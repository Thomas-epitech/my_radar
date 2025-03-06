/*
** EPITECH PROJECT, 2024
** my
** File description:
** task02
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/System/Vector2.h>
    #include <stdbool.h>

    #define ABS(value) (value < 0 ? value * (-1) : value)
    #define MAX(a, b) (a > b ? a : b)

int my_compute_power_rec(int, int);
int my_put_nbr(int);
void my_putchar(char);
int my_putstr(char const *);
char *my_strcpy(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strlen(char const *);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *, char const *, int);
char **my_str_to_word_array(char const *);
void free_double_ptr(void **);
int mini_printf(const char *, ...);
sfVector2f get_vector_normalized(sfVector2f vector);
bool compare_vectors(sfVector2f vec1, sfVector2f vec2, float);
int my_intlen(int);
char *int_to_str(int);
sfVector2f get_perpendicular_vector(sfVector2f vector);
float get_dot_product(sfVector2f vec1, sfVector2f vec2);
float my_atof(char *);
bool str_is_float(char *);
#endif
