/*
** EPITECH PROJECT, 2017
** getline
** File description:
** Description
*/

#include "tetris.h"

int	is_remove(char *str, int save)
{
	int nb_return_line = 0;

	for (int i = 0; str[i] != '\0'; i += 1) {
		if (str[i] == '\n' && str[i + 1] == ' ')
			save += 1;
		if (str[i] == '\n')
			nb_return_line += 1;
	}
	return ((save == nb_return_line + 1 && save != 0) ? 1 : 0);
}

char	*remouve_space(char *str)
{
	char *final = malloc(sizeof(char) * (my_strlen(str) + 1));
	int nb = 0;

	for (int i = 1; str[i - 1] != '\0'; i++) {
		if ((str[i - 1] == '\n' && str[i] == ' '))
			i++;
		final[nb] = str[i];
		nb++;
	}
	final[nb] = '\0';
	return (final);
}

int	chek_error_no_files(DIR* rep)
{
	struct dirent* files_name;
	int nb = 0;

	files_name = readdir(rep);
	while (files_name != NULL) {
		if (strccmp(files_name->d_name, ".tetrimino"))
			nb += 1;
		files_name = readdir(rep);
	}
	if (nb == 0)
		exit(84);
	return (0);
}