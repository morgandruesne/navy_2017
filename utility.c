/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** utility functions for tetris
*/

#include "tetris.h"

void 	print_tetris_tab(core_t *core, int i, int j)
{
	attron(COLOR_PAIR(core->box[i][j] + 2));
	mvprintw(i + 6, j + 21, my_getchar(core->box[i][j]));
	attroff(COLOR_PAIR(core->box[i][j] + 2));
	attron(COLOR_PAIR(core->state.obj[i][j] + 2));
	if (core->state.obj[i][j] != 0)
		mvprintw(i + 6, j + 21, my_getchar(core->state.obj[i][j]));
	attroff(COLOR_PAIR(core->state.obj[i][j] + 2));
}

void 	my_putchar_error(char c)
{
	write(2, &c, 1);
}

void 	my_puterror(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		my_putchar_error(str[i]);
}

char 	*term_var(char **env)
{
	for (int i = 0; env[i] != NULL; i++) {
		if (my_strcmp(env[i], "TERM="))
			return (&env[i][5]);
	}
	return (NULL);
}

void 	display_keycode(char *key)
{
	for (int i = 0; key[i]; i++) {
		if (key[i] == 27)
			my_putstr("^E");
		else if (key[i] == 32)
			my_putstr("(space)");
		else
			my_putchar(key[i]);
	}
}