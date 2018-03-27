/*
** EPITECH PROJECT, 2017
** getline
** File description:
** Description
*/

#include "tetris.h"

char*	remouve_error_char(char *str)
{
	int save = 0;
	int i = 0;

	for (; str[i] != '\0'; i++);
	if (str[i] == '\0' && str[i - 1] == '\n')
		str[i - 1] = '\0'; 
	for (save = 0; !is_remove(str, save); save = 0) {
		if (str[0] == ' ')
			save += 1;
		if (!is_remove(str, save))
			return (str);
		str = remouve_space(str);
	}
	return (str);
}

char	*remouve_char(char *str, int nb)
{
	char *final = malloc(sizeof(char) * (my_strlen(str) + 1));
	int nb2 = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (nb == i)
			i++;
		final[nb2] = str[i];
		nb2++;
	}
	final[nb2] = '\0';
	return (final);

}

char*	remouve_back_space(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if ((str[i] == ' ' && str[i + 1] == '\n')
		|| (str[i] == ' ' && str[i + 1] == '\0')) {
			str = remouve_char(str, i);
			i = 0;
		}
	}
	return (str);
}

void	remouve_to_long_line(tetris_t	*tetris)
{
	int line = 0;
	int nb = 0;

	for (; tetris->model[line + nb] != '\0'; nb += 1) {
		if (nb >= tetris->size[0]
		&& tetris->model[line + nb] != '\n') {
			tetris->model = remouve_char(tetris->model, nb + line);
			line = 0;
			nb = 0;
		}
		if (tetris->model[line + nb] == '\n') {
			line += nb + 1;
			nb = 0;
		}
	}
}

void	error_remouve_finding(tetris_t	*tetris)
{
	while (tetris->next != NULL) {
		if (tetris->error == 0) {
			tetris->model = remouve_error_char(tetris->model);
			tetris->model = remouve_back_space(tetris->model);
			remouve_to_long_line(tetris);
		}
		tetris = tetris->next;
	}
}