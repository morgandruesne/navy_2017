/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** display_tetriminos
*/

#include "tetris.h"

int	display_nb_tetriminos(tetris_t *tetris)
{
	int i = 0;

	while (tetris->next != NULL) {
		i++;
		tetris = tetris->next;
	}
	my_putstr("Tetriminos : ");
	my_putnbr(i);
	my_putstr("\n");
	return (0);
}

int	display_tetriminos(tetris_t *tetris)
{
	while (tetris->next != NULL) {
		my_putstr("Tetriminos : Name ");
		my_putstr(tetris->filename);
		if (tetris->error == 1) {
			my_putstr(" : Error\n");
		} else {
			my_putstr(" : Size ");
			my_putnbr(tetris->size[0]);
			my_putchar('*');
			my_putnbr(tetris->size[1]);
			my_putstr(" : Color ");
			my_putnbr(tetris->color);
			my_putstr(" :\n");
			my_putstr(tetris->model);
			my_putstr("\n");
		}
		tetris = tetris->next;
	}
	return (0);
}
