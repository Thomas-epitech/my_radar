##
## EPITECH PROJECT, 2024
## my lib
## File description:
## my lib
##

CC = gcc

NAME = libmy.a

SRC = my_compute_power_rec.c \
	  my_putchar.c \
	  my_strncpy.c \
	  my_put_nbr.c \
	  my_strcmp.c \
	  my_putstr.c \
	  my_strcpy.c \
	  my_strlen.c \
	  my_strncmp.c \
	  my_str_to_word_array.c \
	  free_double_ptr.c \
	  miniprintf.c \
	  get_vector_normalized.c \
	  compare_vectors.c \
	  int_to_str.c \
	  get_perpendicular_vector.c \
	  get_dot_product.c \
	  my_atof.c \
	  my_intlen.c \
	  str_is_float.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Wshadow -I../../include/

LDFLAGS = -lm

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
