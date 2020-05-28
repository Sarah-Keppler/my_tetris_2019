/*
** EPITECH PROJECT, 2019
** print_tetrimino
** File description:
** Print tetriminos.
*/

#include <stddef.h>
#include "tetris.h"

static void print_name_size_and_color(tetrimino_t *tetri)
{
    my_putstr("Tetrimino :  ");
    my_putstr(tetri->name);
    my_putstr(" :  ");
    if (1 == tetri->check) {
        my_putstr("Error\n");
        return;
    }
    my_putstr("Size ");
    my_put_nbr(tetri->size[0]);
    my_putchar('*');
    my_put_nbr(tetri->size[1]);
    my_putstr(" :  Color ");
    my_put_nbr(tetri->code_color);
    my_putstr(" :\n");
}

void print_tetriminos(debug_t *debug)
{
    tetrimino_t **template = debug->template;
    int i = -1;

    my_putstr("Tetrimino :  ");
    while (template[++i]);
    my_put_nbr(i);
    my_putchar('\n');
    for (int y = 0; template[y]; ++y) {
        print_name_size_and_color(template[y]);
        if (1 == template[y]->check)
            continue;
        my_putstr(template[y]->design[0]);
        for (int s = 0; template[y]->design[s]; ++s) {
            my_putstr(template[y]->design[s]);
            my_putchar('\n');
        }
    }
}
