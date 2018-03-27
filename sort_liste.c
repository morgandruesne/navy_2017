/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** main file
*/

#include "tetris.h"

void	swap(char **final, int nb1, int nb2)
{
	char *temp = malloc(sizeof(char) * (my_strlen(final[nb1])) + 1);
	int i = 0;

	for (i = 0; final[nb1][i] != '\0'; i++)
		temp[i] = final[nb1][i];
	temp[i] = '\0';
	final[nb1] = malloc(sizeof(char) * (my_strlen(final[nb2]) + 1));
	for (i = 0; final[nb2][i] != '\0'; i++)
		final[nb1][i] = final[nb2][i];
	final[nb1][i] = '\0';
	final[nb2] = malloc(sizeof(char) * (my_strlen(temp) + 1));
	for (i = 0; temp[i] != '\0'; i++)
		final[nb2][i] = temp[i];
	final[nb2][i] = '\0';
}

void	sort_liste_alphab(char **array)
{
	int nb = 0;

	for (int i = 0; array[i + 1] != NULL; i++) {
		for (nb = 0; array[i][nb] == array[i + 1][nb] &&
		array[i][nb] != '\0'; nb += 1);
		if (array[i][nb] < array[i + 1][nb]) {
			swap(array, i, i + 1);
			i = -1;
		}
	}
}

char	**insert(char *str, char **temp)
{
	char **final = NULL;
	int size_temp = 0;
	int nb = 0;
	int i = 0;

	for (; temp[size_temp] != NULL; size_temp++);
	final = malloc(sizeof(char *) * (size_temp + 2));
	for (; temp[i] != NULL; i++) {
		final[i] = malloc(sizeof(char) * (my_strlen(temp[i]) + 1));
		for (nb = 0; temp[i][nb] != '\0'; nb++)
			final[i][nb] = temp[i][nb];
		final[i][nb] = '\0';
	}
	final[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
	for (nb = 0; str[nb] != '\0'; nb++)
		final[i][nb] = str[nb];
	final[i++][nb] = '\0';
	final[i] = NULL;
	return (final);
}

char	**get_all_name_sort(DIR* rep, DIR* copy)
{
	struct dirent* files_name;
	char **final = malloc(sizeof(char *) * 2);
	int i = 0;

	chek_error_no_files(copy);
	for (files_name = readdir(rep);
	!strccmp(files_name->d_name, ".tetrimino"); files_name = readdir(rep));
	final[0] = malloc(sizeof(char) * (my_strlen(files_name->d_name) + 1));
	for (i = 0; files_name->d_name[i] != '\0'; i++)
		final[0][i] = files_name->d_name[i];
	final[0][i] = '\0';
	final[1] = NULL;
	for (files_name = readdir(rep); files_name != NULL;
	files_name = readdir(rep)) {
		if (strccmp(files_name->d_name, ".tetrimino"))
			final = insert(files_name->d_name, final);
	}
	sort_liste_alphab(final);
	return (final);
}
