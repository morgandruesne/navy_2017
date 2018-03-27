/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** main game loop
*/

#include "tetris.h"

void	key_handling(core_t *core, int input)
{
	(void)core;
	switch (input) {
		case ' ':
			break;
		case 'q':
			endwin();
			exit(0);
		case KEY_LEFT:
			move_left_tetrimino(core);
			break;
		case KEY_RIGHT:
			move_right_tetrimino(core);
			break;
		case KEY_UP:
			break;
		case KEY_DOWN:
			core->state.delay -= 0.10;
			break;
	}
}

void	display_tetris(core_t *core)
{
	mvprintw(0, 0, "Tetris v. 0.4");
	attron(COLOR_PAIR(1));
	for (int i = 0; i < core->size[0] + 2; i++) {
		mvprintw(i + 5, 20, "|");
		mvprintw(i + 5, 21 + core->size[1], "|");
	}
	for (int i = 0; i < core->size[1] + 2; i++) {
		mvprintw(5, i + 20, "-");
		mvprintw(6 + core->size[0], i + 20, "-");
	}
	attroff(COLOR_PAIR(1));
	for (int i = 0; i < core->size[0]; i++)
		for (int j = 0; j < core->size[1]; j++)
			print_tetris_tab(core, i, j);
}

void 	check_defeat_or_fill(core_t *core, tetris_t *tetris, int i, int *j)
{
	if (core->box[i][*j] != 0) {
		endwin();
		my_putstr("YoU lOoSe NoOb\n");
		exit(0);
	}
	core->state.obj[i][*j] = tetris->color;
	*j += 1;	
}

void	add_tetrimino(core_t *core, tetris_t *tetris)
{
	int	line = 0;
	int	nb = get_good_tetrimino(tetris);
	int	cols = 0;

	core->state.moving = 1;
	for (; nb == 84; nb = get_good_tetrimino(tetris));
	for (int j = 0; j < nb; j++)
		tetris = tetris->next;
	for (int i = 0; tetris->model[i] != '\0'; i++) {
		if (tetris->model[i] == '\n') {
			line += 1;
			cols = 0;
			continue;
		}
		if (tetris->model[i] == ' ') {
			cols += 1;
			continue;
		}
		check_defeat_or_fill(core, tetris, line, &cols);
	}
}

void	game_loop(core_t *core, tetris_t *tetris)
{
	int	input;

	while (1) {
		clear();
		if (core->state.moving == 0)
			add_tetrimino(core, tetris);
		gravity_tetrimino(core);
		display_tetris(core);
		timeout(0.5);
		input = getch();
		key_handling(core, input);
		refresh();
	}
}