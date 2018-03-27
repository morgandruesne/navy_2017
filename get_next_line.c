/*
** EPITECH PROJECT, 2017
** getline
** File description:
** Description
*/

#include "tetris.h"

char	*my_realloc(char *str, int size, int nb)
{
	char *temp = str;

	str = malloc(sizeof(char) * size);
	if (str == NULL)
		exit(84);
	for (int i = 0; i <= nb; i++)
		str[i] = temp[i];
	free(temp);
	return (str);
}

char	get(int fd)
{
	static char buff[READ_SIZE];
	static int size = 0;
	static int nbr = 0;
	char cha;

	if (fd == -42) {
		for (; nbr != size; nbr++)
			buff[nbr] = 0;
		size = 0;
		nbr = 0;
		return (0);
	}
	if (nbr == size) {
		size = read(fd, buff, READ_SIZE);
		nbr = 0;
		if (size == 0)
			return ('\0');
	}
	cha = buff[nbr++];
	return (cha);
}

char	*my_get_next_line(int fd)
{
	char cha;
	char *final;
	int size = 0;

	final = malloc(READ_SIZE + 2);
	if (final == NULL || fd == -1)
		exit(84);
	if (fd == -42) {
		get(fd);
		return (NULL);
	}
	for (size = 0, cha = get(fd); cha != '\n' && cha != '\0'; size++) {
		final[size] = cha;
		cha = get(fd);
		if (size % (READ_SIZE + 1) == 0)
			final = my_realloc(final, size + READ_SIZE + 1, size);
	}
	final[size] = cha;
	final[size + 1] = '\0';
	return (final);
}