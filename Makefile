##
## EPITECH PROJECT, 2017
## makefile_matchstick
## File description:
## makefile
##

SRC	=	main.c				\
		setup_args.c			\
		setup_main.c			\
		setup_tetriminal.c		\
		lib_func.c			\
		lib_func2.c			\
		utility.c			\
		debug_mode.c			\
		get_next_line.c			\
		get_tetrimino.c			\
		get_tetrimino_2.c		\
		display_tetriminos.c		\
		game_utility.c			\
		game_move_check.c		\
		game_move_physics.c		\
		change_value_args.c		\
		error_args.c			\
		sort_liste.c			\
		error.c				\
		game_tetris.c			\
		error_2.c			\

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -I./include/ -lncurses -g3

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o  $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
