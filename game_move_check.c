/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** check if the tetrimino can move
*/

#include "tetris.h"

int	check_move_right(core_t *core)
{
	int	width = core->size[1] - 1;

	for (int j = core->size[1] - 1; j > 0; j--)
		for (int i = 0; i < core->size[0]; i++)
			if ((j == width && core->state.obj[i][j] != 0) ||
			(j != width && core->box[i][j + 1] != 0 &&
			core->state.obj[i][j] != 0)) {
				return (1);
			}
	return (0);
}

int	check_move_left(core_t *core)
{
	for (int j = 0; j < core->size[1] - 1; j++)
		for (int i = 0; i < core->size[0]; i++)
			if ((j == 0 && core->state.obj[i][j] != 0) ||
			(j != 0 && core->box[i][j - 1] != 0 &&
			core->state.obj[i][j] != 0)) {
				return (1);
			}
	return (0);
}

void	check_move_gravity(core_t *core)
{
	int	height = core->size[0] - 1;

	for (int i = core->size[0] - 1; i > 0; i--) {
		for (int j = 0; j < core->size[1]; j++) {
			if ((i == height && core->state.obj[i][j] != 0) ||
			(i != height && core->box[i + 1][j] != 0 &&
			core->state.obj[i][j] != 0)) {
				reset_state_obj(core);
				return;
			}
		}
	}
}