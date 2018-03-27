/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** main setup file
*/

#include "tetris.h"

void 	setup_key_default_value(core_t *core)
{
	core->key.left = (core->key.left == NULL) ?
	tigetstr("kcub1") : core->key.left;
	core->key.right = (core->key.right == NULL) ?
	tigetstr("kcuf1") : core->key.right;
	core->key.turn = (core->key.turn == NULL) ?
	tigetstr("kcud1") : core->key.turn;
	core->key.drop = (core->key.drop == NULL) ?
	tigetstr("kcuu1") : core->key.drop;
	core->key.quit = (core->key.quit == NULL) ? "q" : core->key.quit;
	core->key.pause = (core->key.pause == NULL) ? " " : core->key.pause;
}

void 	setup_default_value(core_t *core)
{
	core->key.left = NULL;
	core->key.right = NULL;
	core->key.turn = NULL;
	core->key.drop = NULL;
	core->key.quit = NULL;
	core->key.pause = NULL;
	core->level = 1;
	core->size[0] = 20;
	core->size[1] = 10;
	core->option[0] = 0;
	core->option[1] = 0;
}

void 	setup_color(void)
{
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(2, COLOR_WHITE, COLOR_WHITE);
	init_pair(3, COLOR_GREEN, COLOR_GREEN);
	init_pair(4, COLOR_RED, COLOR_RED);
	init_pair(5, COLOR_CYAN, COLOR_CYAN);
	init_pair(6, COLOR_BLACK, COLOR_BLACK);
	init_pair(7, COLOR_BLUE, COLOR_BLUE);
	init_pair(8, COLOR_MAGENTA, COLOR_MAGENTA);
}

void 	setup_ncurses(core_t *core)
{
	initscr();
	setup_color();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	core->state.delay = 0.5;
	core->state.moving = 0;
	core->box = malloc(sizeof(int*) * (core->size[0]));
	core->state.obj = malloc(sizeof(int*) * (core->size[0]));
	for (int i = 0; i < core->size[0]; i++) {
		core->box[i] = malloc(sizeof(int) * (core->size[1]));
		core->state.obj[i] = malloc(sizeof(int) * (core->size[1]));
		for (int j = 0; j < core->size[1]; j++) {
			core->box[i][j] = 0;
			core->state.obj[i][j] = 0;
		}
	}
}

void	setup(tetris_t *tetris, core_t *core, char **env)
{
	(void)tetris;
	tgetent(NULL, term_var(env));
	setup_default_value(core);
}