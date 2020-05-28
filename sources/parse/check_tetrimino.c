/*
** EPITECH PROJECT, 2019
** check_tetrimino
** File description:
** Check a tetrimino.
*/

#include "tetris.h"

static char check_design(char *line)
{
    for (int i = 0; line[i]; ++i)
        if ('*' != line[i] && ' ' != line[i])
            return ('1');
    return ('0');
}

static char check_size_and_color(char *line)
{
    int nbr = 0;

    for (int i = 0; line[i]; ++i) {
        if (!('0' <= line[i] && '9' >= line[i]) && ' ' != line[i])
            return ('1');
        if (' ' == line[i])
            ++nbr;
    }
    if (2 != nbr)
        return ('1');
    return ('0');
}

void check_a_tetrimino(tetrimino_t *tetrimino, char **buf)
{
    if ('1' == check_size_and_color(buf[0])) {
        tetrimino->check = 1;
        return;
    }
    for (int i = 1; buf[i]; ++i) {
//        my_putstr(buf[i]);
//        my_putchar('\n');
        if ('1' == check_design(buf[i])) {
            tetrimino->check = 1;
            return;
        }
    }
}

char check_tetrimino_file(char const *name)
{
    int index = -1;

    for (int i = 0; name[i]; ++i)
        if ('.' == name[i])
            index = i;
    if (0 == my_strcmp(name + index, ".tetrimino"))
        return ('0');
    return ('1');
}
