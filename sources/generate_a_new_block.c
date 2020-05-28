/*
** EPITECH PROJECT, 2019
** next_block
** File description:
** Get the next block, one from the models.
*/

#include <stddef.h>
#include <stdlib.h>
#include "tetris.h"

void display_a_tetri(tetrimino_t *tetri)
{
    for (int i = 0; tetri->design[i]; ++i) {
        my_putstr(tetri->design[i]);
        my_putchar('\n');
    }
}

tetrimino_t *get_the_next_tetri(game_t *game)
{
    int random = 0;
    tetrimino_t *new = NULL;
    int i = -1;

    while (game->template[++i]);
    if ('1' == my_rand(&random, 0, i - 1))
        return (NULL);
    new = game->template[random];
    if (NULL == new)
        return (NULL);
    return (new);
}
