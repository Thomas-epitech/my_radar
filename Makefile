##
## EPITECH PROJECT, 2024
## radar
## File description:
## makefile
##

CC = gcc

NAME = my_radar

LIB_NAME = lib/my/libmy.a

SRC = src/main.c \
	  src/get_script_info.c \
	  src/initialize_data.c \
	  src/free_data.c \
	  src/game_loop.c \
	  src/handle_events.c \
	  src/update_game_state.c \
	  src/render_game.c \
	  src/get_plane_vertices.c \
	  src/check_plane_collision.c \
	  src/update_grid.c \
	  src/plane_is_near_tower.c \
	  src/print_help_message.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Wshadow -Iinclude/

LDFLAGS = -Llib/my -lmy -lcsfml-system -lcsfml-window -lcsfml-graphics -lm

all: $(NAME)

$(LIB_NAME):
	make -C lib/my

$(NAME): $(LIB_NAME) $(OBJ)
	$(CC) -pg -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run: all
	make -C tests/
	tests/unit_tests
