/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** Tetris's structs.
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#define ARGS_MAX 10
#define KEYS_MAX 6

typedef struct arg_s {
    char const *lname;
    char val;
    char const *optarg;
} arg_t;

#define PATH_TETRIMINO "./tetriminos/"

typedef struct tetrimino_s {
    char *name;
    int code_color;
    int size[2];
    char **design;
    int check;
} tetrimino_t;

typedef struct debug {
    int level;
    char *infos[ARGS_MAX];
    char *keys[KEYS_MAX];
    int map_size[2];
    char without_next;
    char debug;
    tetrimino_t **template;
    char **buf;
} debug_t;

typedef struct board_s {
    char **block_map;
    float speed;
    int position[2];
    tetrimino_t *current_tetri;
    tetrimino_t *next_tetri;
} board_t;

typedef struct game_s {
    tetrimino_t **template;
    char **keys;
    int size[2];
    int high_score;
    int score;
    int lines;
    int level;
    char next;
    board_t *board;
} game_t;

#endif /* STRUCT_H_ */
