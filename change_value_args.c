/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** change values in args
*/

#include "tetris.h"

char	*change_key(char *key)
{
	int	index = 0;

	if (my_strlen(optarg) == 0) {
		my_puterror("[*] Invalid input\n");
		exit(84);
	}
	key = malloc(sizeof(char) * (my_strlen(optarg) + 1));
	for (; optarg[index] != '\0'; index++)
		key[index] = optarg[index];
	key[index] = 0;
	return (key);
}

void	change_level(core_t *core)
{
	for (int i = 0; optarg[i] != '\0'; i++)
		if (my_strlen(optarg) >= 10 || optarg[i] < '0' ||
		optarg[i] > '9') {
			my_puterror("[*] Invalid input\n");
			exit(84);
		}
	core->level = my_get_nbr(optarg);
	if (core->level == 0) {
		my_puterror("[*] Invalid input\n");
		exit(84);	
	}
}

void	change_map_size_check_valid_expr(void)
{
	int	allowed_character = 0;

	for (int i = 0; optarg[i] != '\0'; i++) {
		if (allowed_character == 0 && optarg[i] == ',') {
			allowed_character += 1;
			continue;
		}
		if (optarg[i] < '0' || optarg[i] > '9') {
			my_puterror("[*] Invalid input\n");
			exit(84);
		}
	}
}

void	change_map_size(core_t *core)
{
	int	index = 0;

	change_map_size_check_valid_expr();
	core->size[0] = my_get_nbr(optarg);
	for (; optarg[index] != '\0'; index++)
		if (optarg[index] == ',') {
			index++;
			break;
		}
	core->size[1] = my_get_nbr(optarg + index);
	if (core->size[0] <= 0 || core->size[1] <= 0) {
		my_puterror("[*] Invalid input\n");
		exit(84);
	}
}