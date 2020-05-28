/*
** EPITECH PROJECT, 2019
* * print_debug
** File description:
** Print the debug.
*/

#include <stdio.h>
#include <unistd.h>
#include <termio.h>
#include "tetris.h"

static char check_each_key(char **keys, int y)
{
    for (int i = 0; KEYS_MAX > i; ++i)
        if (i != y && 0 == my_strcmp(keys[i], keys[y])) {
            my_puterror("Error : severals sequences start ");
            my_puterror("with the same values\n");
            return ('1');
        }
    return ('0');
}

static void print_level_map_and_next(debug_t *debug)
{
    if ('0' == debug->without_next)
        my_putstr("Yes\n");
    else
        my_putstr("No\n");
    my_putstr("Level :  ");
    my_put_nbr(debug->level);
    my_putchar('\n');
    my_putstr("Size :  ");
    my_put_nbr(debug->map_size[0]);
    my_putchar('*');
    my_put_nbr(debug->map_size[1]);
    my_putchar('\n');
}

static void print_name_and_data(char const *name, char const *data)
{
    my_putstr(name);
    my_putstr(" :  ");
    if (0 == my_strcmp(" ", data))
        my_putstr("(space)");
    else
        my_putstr(data);
    my_putchar('\n');
}

char print_debug(debug_t *debug)
{
    char *buf;
    char *key_name[KEYS_MAX] = {"Key Left", "Key Right", "Key Turn",
        "Key Drop", "Key Quit", "Key Pause"};

    for (int i  = 0; KEYS_MAX > i; ++i)
        if ('1' == check_each_key(debug->keys, i))
            return ('1');
    if ('1' == debug->debug)
        return ('0');
    my_putstr("*** DEBUG MODE ***\n");
    for (int i = 0; KEYS_MAX > i; ++i)
        print_name_and_data(key_name[i], debug->keys[i]);
    print_level_map_and_next(debug);
    print_tetriminos(debug);
    my_putstr("Press any key to start Tetris\n");
    while (0 == read(0, &buf, 1));
    return ('0');
}
