/*
** EPITECH PROJECT, 2019
** tetris.h
** File description:
** Functions of Tetris.
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include "my.h"
#include "struct.h"

debug_t *init_debug(void);
arg_t *create_an_arg(int);
void fill_debug(debug_t *);

char parse_opts(int, char **, debug_t *);

char print_debug(debug_t *);

char read_each_tetriminos(debug_t *);

tetrimino_t **create_a_template(void);
char add_a_template(debug_t *, tetrimino_t *);
tetrimino_t *create_a_tetrimino(char *);
char fill_a_tetrimino(tetrimino_t *, char **);

void check_a_tetrimino(tetrimino_t *, char **);
char check_tetrimino_file(char const *);
char check_an_arg(arg_t *);

game_t *init_game(debug_t *);

void print_tetriminos(debug_t *);
void print_help(char *);

void display_a_tetri(tetrimino_t *);
tetrimino_t *get_the_next_tetri(game_t *);
char display_the_game(game_t *);
char drop_a_tetrimino(game_t *, board_t *);
char prepare_blocks(game_t *, board_t *);
char game_routine(game_t *);
char key_event(game_t *);
int *recup_keys(char **);
void move_left(game_t *);
void move_right(game_t *);

void print_board(board_t *);

#endif /* TETRIS_H_ */
