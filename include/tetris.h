/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** tetris header
*/

#ifndef __TETRIS_H__
#define __TETRIS_H__

#ifndef  READ_SIZE
#define  READ_SIZE (10)
#endif

#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <ncurses.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <term.h>
#include <getopt.h>

typedef struct tetris_s {
	int	error;
	char	*filename;
	int		size[2];
	int	color;
	char	*model;
	struct	tetris_s *next;
} tetris_t;

typedef struct keys_s {
	char	*left;
	char	*right;
	char	*turn;
	char	*drop;
	char	*quit;
	char	*pause;
} keys_t;

typedef struct state_s {
	int		moving;
	int		**obj;
	double	delay;
} state_t;

typedef struct core_s {
	keys_t 	key;
	int		level;
	int		size[2];
	int		option[2];
	int		**box;
	state_t state;
} core_t;

void	error_remouve_finding(tetris_t	*tetris);

/* Library functions */
void	my_putstr(char *str);
int	my_strlen(char *str);
void	my_putchar(char c);
char	*my_concat(char *str, char *str2);
int	my_strcmp(char *str, char *tofind);
char	*my_get_next_line(int fd);
int	my_putnbr(int nb);
int	strccmp(char *str, char *str2);
int	my_get_nbr(char *str);
char	*my_getchar(int nbr);
void 	my_puterror(char *str);

void	setup(tetris_t *tetris, core_t *core, char **env);
void	setup_user_input(int ac, char **av, core_t *core);
void	setup_key_default_value(core_t *core);
void	check_error_keybinding(core_t *core);
void	setup_ncurses(core_t *core);
char	*remouve_space(char *str);
int		are_three_arg(char *str);
int		is_remove(char *str, int save);
void	debug_mode(tetris_t *tetris, core_t *core);

tetris_t*	get_all_tetrimimo(tetris_t *tetris);
tetris_t*	get_tetrimimo(char *path, tetris_t *tetris);
int	get_tetrimino_first_line(int fd, tetris_t *tetris);
int	get_tetrimino_form(int fd, tetris_t *tetris);
char	*get_filename_no_ext(char *path);
void	display_keycode(char *key);

int	display_nb_tetriminos(tetris_t *tetris);
char	**get_all_name_sort(DIR* rep, DIR* copy);
int	display_tetriminos(tetris_t *tetris);

void	game_loop(core_t *core, tetris_t *tetris);
void	check_tetrimino_all_errors(tetris_t *tetris);

/* Game Utility */
void	reset_state_obj(core_t *core);
int	get_good_tetrimino(tetris_t *tetris);
int	nb_tetriminos(tetris_t *tetris);
void 	print_tetris_tab(core_t *core, int i, int j);

/* Game Physics */
void	move_left_tetrimino(core_t *core);
void	move_right_tetrimino(core_t *core);
void	gravity_tetrimino(core_t *core);
void	rotation_tetrimino(core_t *core);
int	check_move_right(core_t *core);
int	check_move_left(core_t *core);
void	check_move_gravity(core_t *core);

/* Utility functions */
char	*term_var(char **env);
void	display_keycode(char *key);

/* Change values of default values */
void	change_map_size(core_t *core);
void	change_level(core_t *core);
char	*change_key(char *key);
int	chek_error_no_files(DIR* rep);

#endif
