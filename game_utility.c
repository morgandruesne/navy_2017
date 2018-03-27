/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** utility functions for the game
*/

#include "tetris.h"

int	nb_tetriminos(tetris_t *tetris)
{
	int i = 0;

	while (tetris->next != NULL) {
		i++;
		tetris = tetris->next;
	}
	i = rand() % i;
	return (i);
}

int	get_good_tetrimino(tetris_t *tetris)
{
	int	i = nb_tetriminos(tetris);

	for (int j = 0; j < i; j++)
		tetris = tetris->next;
	if (tetris->error == 1)
		return (84);
	return (i);
}

void	destroy_line(core_t *core, int line)
{
	for (int i = line; i > 0; i--) {
		for (int j = 0; j < core->size[1]; j++)
			core->box[i][j] = core->box[i - 1][j];
	}
}

void	complete_line(core_t *core)
{
	int	checked = 0;

	for (int i = 0; i < core->size[0]; i++) {
		for (int j = 0; j < core->size[1]; j++)
			checked += (core->box[i][j] != 0) ? 1 : 0;
		if (checked == core->size[1])
			destroy_line(core, i);
		checked = 0;
	}
}

void	reset_state_obj(core_t *core)
{
	for (int i = 0; i < core->size[0]; i++)
		for (int j = 0; j < core->size[1]; j++) {
			if (core->state.obj[i][j] != 0)
				core->box[i][j] = core->state.obj[i][j];
			core->state.obj[i][j] = 0;
		}
	complete_line(core);
	core->state.moving = 0;
}