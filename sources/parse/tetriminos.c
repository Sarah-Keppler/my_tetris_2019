/*
** EPITECH PROJECT, 2019
** tetrimino
** File description:
** Create and stock tetriminos.
*/

#include <stddef.h>
#include <stdlib.h>
#include "tetris.h"

static char **copy_design(char **buf)
{
    char **new = NULL;
    int i = -1;

    while (buf[++i]);
    new = malloc(sizeof(char *) * i);
    if (NULL == new)
        return (NULL);
    for (int y = 0; buf[y + 1]; ++y) {
        new[y] = malloc(sizeof(char) * (my_strlen(buf[y + 1]) + 1));
        if (NULL == new[y])
            return (NULL);
        for (int s = 0; buf[y + 1][s]; ++s) {
            new[y][s] = buf[y + 1][s];
            new[y][s + 1] = '\0';
        }
    }
    new[i - 1] = NULL;
    return (new);
}

char fill_a_tetrimino(tetrimino_t *tetrimino, char **buf)
{
    int index[2] = {0, 0};
    int y = -1;

    if (1 == tetrimino->check)
        return ('0');
    for (int i = 0; buf[0][i]; ++i)
        if (' ' == buf[0][i])
            index[++y] = i;
    tetrimino->code_color = my_getnbr(buf[0] + index[1] + 1);
    tetrimino->size[0] = my_getnbr(buf[0]);
    tetrimino->size[1] = my_getnbr(buf[0] + index[0] + 1);
    tetrimino->design = copy_design(buf);
    if (NULL == tetrimino->design)
        return ('1');
    return ('0');
}

static char *copy_the_name(char *name)
{
    int i = -1;
    char *copy = NULL;

    for (int s = 0; name[s]; ++s)
        if ('.' == name[s])
            i = s;
    if (-1 != i) {
        copy = malloc(sizeof(char) * (i + 2));
        if (NULL == copy)
            return (NULL);
        my_strncpy(copy, name, i);
    } else {
        copy = malloc(sizeof(char) * (my_strlen(name) + 1));
        if (NULL == copy)
            return (NULL);
        my_strcpy(copy, name);
    }
    return (copy);
}

tetrimino_t *create_a_tetrimino(char *name)
{
    tetrimino_t *new = malloc(sizeof(tetrimino_t));

    if (NULL == new)
        return (NULL);
    new->name = copy_the_name(name);
    if (NULL == new->name)
        return (NULL);
    new->code_color = -1;
    new->size[0] = -1;
    new->size[1] = -1;
    new->design = NULL;
    new->check = 0;
    return (new);
}

char add_a_template(debug_t *debug, tetrimino_t *tetrimino)
{
    int i = -1;
    tetrimino_t **new = NULL;

    while (debug->template[++i]);
    new = malloc(sizeof(tetrimino_t *) * (i + 2));
    if (NULL == new)
        return ('1');
    for (int y = 0; debug->template[y]; ++y)
        new[y] = debug->template[y];
    new[i] = tetrimino;
    new[i + 1] = NULL;
    free(debug->template);
    debug->template = new;
    return ('0');
}
