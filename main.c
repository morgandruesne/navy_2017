/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** main file
*/

#include "tetris.h"

int	main(int ac, char **av, char **env)
{
	tetris_t	*tetris = malloc(sizeof(tetris_t));
	core_t 		core;

	tetris->next = NULL;
	if (env[0] == NULL || env == NULL)
		return (84);
	setup(tetris, &core, env);
	setup_user_input(ac, av, &core);
	tetris = get_all_tetrimimo(tetris);
	error_remouve_finding(tetris);
	setup_key_default_value(&core);
	check_error_keybinding(&core);
	debug_mode(tetris, &core);
	check_tetrimino_all_errors(tetris);
	setup_ncurses(&core);
	game_loop(&core, tetris);
	return (0);
}
