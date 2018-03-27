/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** basic functions part 2
*/

#include "tetris.h"

int	my_putnbr(int nb)
{
	int	right;
	int	left;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	left = nb % 10;
	right = nb / 10;
	if (right != 0)
		my_putnbr(right);
	my_putchar(left + '0');
	return (0);
}

char	*str_fill(char *str, int nbr, int tmp, int length)
{
	int i = 0;

	while (i != length) {
		str[i++] = (nbr / tmp) % 10 + '0';
		tmp /= 10;
	}
	str[i] = '\0';
	return (str);
}

int	nbr_length_getchar(int nbr, int *tmp)
{
	int	length = 0;

	while (nbr / *tmp > 0) {
		*tmp *= 10;
		length++;
	}
	return (length);
}

char	*my_getchar(int nbr)
{
	char	*str;
	int	tmp = 1;
	int	length = 0;

	str = malloc(sizeof(char) * 10);
	if (!str)
		return (NULL);
	if (nbr == 0)
		return ("0");
	length = nbr_length_getchar(nbr, &tmp);
	tmp /= 10;
	str = str_fill(str, nbr, tmp, length);
	return (str);
}

int my_get_nbr(char *str)
{
	int i = 0;
	int moins = 1;
	int result = 0;

	if (str[0] == '-') {
		moins = -1;
		i += 1;
	}
	for (; str[i] >= '0' && str[i] <= '9'; i += 1)
		result = result * 10 + (str[i] - '0');
	result = result * moins;
	return (result);
}