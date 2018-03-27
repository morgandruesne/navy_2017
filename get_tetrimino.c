/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** main file
*/

#include "tetris.h"

int	get_tetrimino_first_line(int fd, tetris_t *tetris)
{
	char *str = my_get_next_line(fd);
	int save = 0;
	int i = 0;

	for (; str[i] != '\0'; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || are_three_arg(str))
			return (84);
		save += (str[i] >= '0' && str[i] <= '9') ? 1 : 0;
	}
	if (i <= 1 || save < 1)
		return (84);
	for (i = 0; (str[i] >= '0' && str[i] <= '9') && str[i] == '-'; i++);
	tetris->size[0] = my_get_nbr(str + i);
	for (; (str[i] >= '0' && str[i] <= '9') || str[i] == '-'; i++);
	for (; !((str[i] >= '0' && str[i] <= '9') || str[i] == '-'); i++);
	tetris->size[1] = my_get_nbr(str + i);
	for (; (str[i] >= '0' && str[i] <= '9') || str[i] == '-'; i++);
	for (; !((str[i] >= '0' && str[i] <= '9') || str[i] == '-'); i++);
	tetris->color = my_get_nbr(str + i);
	return (0);
}

int	error_cheking(char *str)
{
	int chek_star = 0;

	if (str[0] == '\0')
		return (84);
	for (int i = 0; str[i] != '\0'; i++) {
		if (!(str[i] == '*' || str[i] == ' ' || str[i] == '\n'))
			return (84);
		if (str[i] == '*')
			chek_star += 1;
	}
	return ((chek_star > 0) ? 0 : 84);
}

char	*get_filename_no_ext(char *path)
{
	int i = 0;
	int len = 0;
	char *final;

	for (; path[i] != '\0'; i++);
	for (; path[i] != '/' && i != 0; i--);
	for (; path[i] != '.' && path[i] != '\0'; i++)
		len += 1;
	final = malloc(sizeof(char) * len + 1);
	for (; path[i] != '/' && i != 0; i--);
	for (len = 0, i += 1; path[i] != '.' && path[i] != '\0'; i++) {
		final[len] = path[i];
		len += 1;
	}
	final[len] = '\0';
	return (final);
}

int	get_tetrimino_form(int fd, tetris_t *tetris)
{
	char *str = malloc(sizeof(char) * 1);
	int error = 0;

	tetris->model = my_get_next_line(fd);
	str[0] = 'a';
	for (int i = 1; i < tetris->size[1]; i += 1) {
		str = my_get_next_line(fd);
		error = error_cheking(str);
		if (error != 0)
			return (84);
		tetris->model = my_concat(tetris->model, str);
	}
	return (0);
}
