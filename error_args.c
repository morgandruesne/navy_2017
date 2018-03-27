/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** checking user input in arguments
*/

#include "tetris.h"

void	check_keybinding_compare(char *str, char *str2, int i, int j)
{
	if (i == j)
		return;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != str2[i])
			return;
		if (str[i + 1] == '\0' && str2[i + 1] == '\0') {
			my_puterror("[*] Invalid parameter\n");
			exit(84);
		}
	}
}

void	check_error_keybinding(core_t *core)
{
	char 	*array[6] =
	{
		core->key.left, core->key.right, core->key.turn,
		core->key.drop, core->key.quit, core->key.pause
	};

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			check_keybinding_compare(array[i], array[j], i, j);
}