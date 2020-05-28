/*
** EPITECH PROJECT, 2018
** print_help
** File description:
** Print help.
*/

#include "tetris.h"

static void print_help_part2(void)
{
    my_putstr("using the K key (def: top arrow)\n"
        " -d --key-drop={K}\tDROP the tetrimino using the K"
        " key (def: down arrow)\n"
        " -q --key-quit={K}\tQUIT the game using the K key"
        " (def: 'q' key)\n"
        " -p --key-pause={K}\tPAUSE/RESTART the game using"
        " the K key (def: space bar)\n"
        " --map-size={row,col}\tSet the numbers of rows and"
        " columns of the map (def: 20,10)\n"
        " -w --without-next\tHide next tetrimino (def: false)\n"
        " -D --debug\t\tDebug mode (def: false)\n");
}

void print_help(char *av)
{
    my_putstr("Usage: ");
    my_putstr(av);
    my_putstr(" [options]\n"
        "Options:\n"
        " --help\t\t\tDisplay this help\n"
        " -L --level={num}\tStart Tetris at level num (def: 1)\n"
        " -l --key-left={K}\tMove the tetrimino LEFT using "
        "the K key (def: left arrow)\n"
        " -r --key-right={K}\tMove the tetrimino RIGHT"
        " using the K key (def: right arrow)\n"
        " -t --key-turn={K}\tTurn the tetrimino clockwise 90d ");
    print_help_part2();
}
