/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetriminos related setup functions
*/

#include "tetris.h"

tetris_t	*get_tetrimimo(char *path, tetris_t *tetris)
{
	int i = 0;
	int chek = 0;
	tetris_t *tetris2 = malloc(sizeof(*tetris));
	int fd = open(path, O_RDONLY);

	my_get_next_line(-42);
	if (fd == -1 || open(path, O_DIRECTORY) != -1)
		return (tetris);
	chek = get_tetrimino_first_line(fd, tetris2);
	if (chek != 84 || tetris2->size[0] < 1 || tetris2->size[1] < 1)
		i = get_tetrimino_form(fd, tetris2);
	tetris2->filename = get_filename_no_ext(path);
	if (i == 84 || chek == 84)
		tetris2->error = 1;
	else
		tetris2->error = 0;
	close(fd);
	tetris2->next = tetris;
	return (tetris2);
}

void	check_tetrimino_all_errors(tetris_t *tetris)
{
	int 	check = 0;
	int	i = 0;

	while (tetris->next != NULL) {
		check += (tetris->error == 1) ? 1 : 0;
		i++;
		tetris = tetris->next;
	}
	if (check == i)
		exit(84);
}

tetris_t	*get_all_tetrimimo(tetris_t *tetris)
{
	DIR* rep = opendir("./tetriminos");
	char **files;

	if (rep == NULL)
		exit (84);
	files = get_all_name_sort(rep, opendir("./tetriminos"));
	if (files == NULL)
		exit (84);
	for (int i = 0; files[i] != NULL; i += 1) {
		if (strccmp(files[i], ".tetrimino")) {
			tetris = get_tetrimimo(my_concat("tetriminos/",
			files[i]), tetris);
		}
	}
	return (tetris);
}
