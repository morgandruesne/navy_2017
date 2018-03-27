/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** basic functions
*/

#include "tetris.h"

int	my_strcmp(char *str, char *tofind)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (tofind[i + 1] == '\0')
			return (1);
		if (str[i] != tofind[i])
			return (0);
	}
	return (0);
}

int	my_strlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i += 1;
	return (i);
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	strccmp(char *str, char *str2)
{
	int y = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str2[y + 1] == '\0')
			return (1);
		else if (str[i] != str2[y])
			y = 0;
		else
			y++;
	}
	return (0);
}

void	my_putstr(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
}
