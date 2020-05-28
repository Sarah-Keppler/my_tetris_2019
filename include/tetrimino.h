/*
** EPITECH PROJECT, 2019
** tetrimino.h
** File description:
** Struct of tetriminos.
*/

#ifndef TETRIMINO_H_
#define TETRIMINO_H_

#define PATH_TETRIMINO "./tetriminos/"

typedef struct tetrimino_s {
    char *name;
    int code_color;
    int size[2];
    char **design;
    int check;
} tetrimino_t;

#endif /* TETRIMINO_H_ */
