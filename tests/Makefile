##
## EPITECH PROJECT, 2024
## my radar
## File description:
## test Makefile
##

CC = gcc

NAME = unit_tests

SRC = ../src/get_script_info.c \
	  ../src/get_plane_vertices.c \
	  script_err_tests.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Wshadow -I../include/

LDFLAGS = -L../lib/my/ -lmy -lcriterion -lcsfml-system -lcsfml-window -lcsfml-graphics -lm --coverage

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
