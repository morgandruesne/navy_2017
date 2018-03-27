/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** options setup file
*/

#include "tetris.h"

void 	user_keybinding(int out, core_t *core)
{
	switch (out) {
		case 'l':
			core->key.left = change_key(core->key.left);
			break;
		case 'r':
			core->key.right = change_key(core->key.right);
			break;
		case 't':
			core->key.turn = change_key(core->key.turn);
			break;
		case 'd':
			core->key.drop = change_key(core->key.drop);
			break;
		case 'q':
			core->key.quit = change_key(core->key.quit);
			break;
		case 'p':
			core->key.pause = change_key(core->key.pause);
			break;
	}
}
void 	user_corebinding(int out, core_t *core)
{
	switch (out) {
		case 'D':
			core->option[0] = 1;
			break;
		case 'w':
			core->option[1] = 1;
			break;
		case 0:
			change_map_size(core);
			break;
		case 'L':
			change_level(core);
			break;
	}
}

void 	user_help(int out, char **av)
{
	if (out != 1)
		return;
	my_putstr("Usage:  ");
	my_putstr(av[0]);
	my_putstr(" [options]\nOptions:\n  --help\t\tDisplay this help\n");
	my_putstr("  -L --level={num}\tStart Tetris at level num (def: 1)\n");
	my_putstr("  -l --key-left={K}\tMove the tetrimino LEFT using the K ke"
	"y (def: left arrow)\n  -r --key-right={K}\tMove the tetrimino RIGHT u"
	"sing the K key (def: right arrow)\n  -t --key-turn={K}\tTURN the tetr"
	"imino clockwise 90d usinng the K key (def: top arrow)\n");
	my_putstr("  -d --key-drop={K}\tDROP the tetrimino using the K key "
	"(def: down arrow)\n  -q --key-quit={K}\tQUIT the game using the K key"
	" (def: 'q' key)\n");
	my_putstr("  -p --key-pause={K}\tPAUSE/RESTART the game using the K"
	" key (def: space bar)\n");
	my_putstr("  --map-size={row,col}\tSet the numbers of rows and columns"
	" of the map (def: 20,10)\n");
	my_putstr("  -w --without-next\tHide next tetrimino (def: false)\n");
	my_putstr("  -D --debug\t\tDebug mode (def: false)\n");
	exit(0);
}

void 	user_arguments(int out, core_t *core, char **av)
{
	if (out == '?')
		exit(84);
	user_help(out, av);
	user_keybinding(out, core);
	user_corebinding(out, core);
}

void 	setup_user_input(int ac, char **av, core_t *core)
{
	struct option options[] = {
		{"level", required_argument, 0, 'L'},
		{"key-left", required_argument, 0, 'l'},
		{"key-right", required_argument, 0, 'r'},
		{"key-turn", required_argument, 0, 't'},
		{"key-drop", required_argument, 0, 'd'},
		{"key-quit", required_argument, 0, 'q'},
		{"key-pause", required_argument, 0, 'p'},
		{"map-size", required_argument, 0, 0},
		{"without-next", no_argument, 0, 'w'},
		{"debug", no_argument, 0, 'D'},
		{"help", no_argument, 0, 1}
	};

	for (int out = 1; 1;) {
		out = getopt_long(ac, av, "Dwp:q:d:t:r:l:L:", options, NULL);
		if (out == -1)
			break;
		user_arguments(out, core, av);
	}
}