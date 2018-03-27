/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** debug mode file
*/

#include "tetris.h"

void	display_keybinding(core_t *core)
{
	my_putstr("Key Left :  ");
	display_keycode(core->key.left);
	my_putstr("\nKey Right :  ");
	display_keycode(core->key.right);
	my_putstr("\nKey Turn :  ");
	display_keycode(core->key.turn);
	my_putstr("\nKey Drop :  ");
	display_keycode(core->key.drop);
	my_putstr("\nKey Quit :  ");
	display_keycode(core->key.quit);
	my_putstr("\nKey Pause :  ");
	display_keycode(core->key.pause);
	my_putstr("\n");
}

void	enable_termcaps(int enable)
{
	struct termios term;

	tcgetattr(0, &term);
	if (enable == 1) {
		term.c_lflag &= ~(ICANON);
		term.c_lflag &= ~(ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		tcsetattr(0, TCSADRAIN, &term);
		return;
	}
	term.c_lflag = (ICANON | ECHO);
	tcsetattr(0, 0, &term);
}

void	display_core_params(core_t *core)
{
	my_putstr("Next :  ");
	if (core->option[1] == 0)
		my_putstr("Yes\n");
	else
		my_putstr("No\n");
	my_putstr("Level :  ");
	my_putnbr(core->level);
	my_putstr("\nSize :  ");
	my_putnbr(core->size[0]);
	my_putstr("*");
	my_putnbr(core->size[1]);
	my_putstr("\n");
}

void	debug_mode(tetris_t *tetris, core_t *core)
{
	char	*out;

	if (core->option[0] != 1)
		return;
	(void)tetris;
	enable_termcaps(1);
	my_putstr("*** DEBUG MODE ***\n");
	display_keybinding(core);
	display_core_params(core);
	display_nb_tetriminos(tetris);
	display_tetriminos(tetris);
	my_putstr("Press any key to start Tetris\n");
	read(0, &out, 1);
	enable_termcaps(0);
	return;
}
