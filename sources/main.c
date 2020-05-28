/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** First Year Project Epitech: Rebuild a tetris. Enjoy the song.
*/

#include <stdio.h>
#include <ncurses.h>
#include "tetris.h"

static char init_tetris(int ac, char **av, debug_t *debug)
{
    if ('1' == parse_opts(ac, av, debug))
        return ('1');
    fill_debug(debug);
    if ('1' == read_each_tetriminos(debug))
        return ('1');
    if ('1' == print_debug(debug))
        return ('1');
    return ('0');
}

char run(int ac, char **av)
{
    debug_t *debug = init_debug();
    game_t *game = NULL;

    if (NULL == debug || '1' == init_tetris(ac, av, debug))
        return ('1');
    game = init_game(debug);
    if (NULL == game)
        return ('1');
    initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    if ('1' == game_routine(game))
        return ('1');
    endwin();
    return ('0');
}

int main(int ac, char **av)
{
    for (int i = 0; ac > i; ++i)
        if (0 == my_strcmp(av[i], "--help")) {
            print_help(av[0]);
            return (0);
        }
    if ('1' == run(ac, av)) {
        my_putchar('\n');
        print_help(av[0]);
        return (84);
    }
    return (0);
}
