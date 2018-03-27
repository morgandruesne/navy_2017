/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** main file
*/

#include "tetris.h"

char	*my_concat(char *str, char *str2)
{
	int	len1 = my_strlen(str);
	int	len2 = my_strlen(str2);
	char	*final = malloc(sizeof(char) * (len1 + len2 + 1));

	for (int i = 0; i != (len1 + len2 + 1); i++)
		final[i] = '\0';
	for (len1 = 0; str[len1] != '\0'; len1++)
		final[len1] = str[len1];
	for (len2 = 0; str2[len2] != '\0'; len2++)
		final[len1 + len2] = str2[len2];
	return (final);

}

int	are_three_arg(char *str)
{
	int nb = 0;
	int rtn = 0;
	int save = 0;

	for (int i = 0; str[i] != '\0'; i += 1) {
		if ((str[i] >= '0' && str[i] <= '9') && save == 0) {
			save = 1;
			nb++;
		}
		if (!(str[i] >= '0' && str[i] <= '9') && save == 1)
			save = 0;
	}
	rtn = (nb == 3) ? 0 : 1;
	return (rtn);
}