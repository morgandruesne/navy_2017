/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** move handling in game
*/

#include "tetris.h"

void	move_left_tetrimino(core_t *core)
{
	if (check_move_left(core))
		return;
	for (int j = 0; j < core->size[1] - 1; j++)
		for (int i = 0; i < core->size[0]; i++)
			if (core->state.obj[i][j + 1] != 0) {
				core->state.obj[i][j] =
				core->state.obj[i][j + 1];
				core->state.obj[i][j + 1] = 0;
			}
}

void	move_right_tetrimino(core_t *core)
{
	if (check_move_right(core))
		return;
	for (int j = core->size[1] - 1; j > 0; j--)
		for (int i = 0; i < core->size[0]; i++)
			if (core->state.obj[i][j - 1] != 0) {
				core->state.obj[i][j] =
				core->state.obj[i][j - 1];
				core->state.obj[i][j - 1] = 0;
			}
}

void	gravity_tetrimino(core_t *core)
{
	double my_clock = (double)clock() / (double)CLOCKS_PER_SEC;

	if (my_clock < core->state.delay)
		return;
	check_move_gravity(core);
	for (int i = core->size[0] - 1; i > 0; i--) {
		for (int j = 0; j < core->size[1]; j++) {
			if (core->state.obj[i - 1][j] != 0) {
				core->state.obj[i][j] =
				core->state.obj[i - 1][j];
				core->state.obj[i - 1][j] = 0;
			}
		}
	}
	core->state.delay += 0.25;
}

void	rotation_tetrimino(core_t *core)
{
	(void)core;
	return;
}