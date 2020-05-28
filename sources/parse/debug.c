/*
** EPITECH PROJECT, 2019
** debug
** File description:
** Init the debug.
*/

#include <stdlib.h>
#include "opt.h"
#include "tetris.h"

static void fill_map_in_debug(debug_t *debug)
{
    char **infos = debug->infos;
    int i = -1;

    if (NULL == infos[7])
        return;
    debug->map_size[0] = my_getnbr(infos[7]);
    while (',' != infos[7][++i]);
    debug->map_size[1] = my_getnbr(infos[7] + i + 1);
}

void fill_debug(debug_t *debug)
{
    char **infos = debug->infos;
    char *def_keys[KEYS_MAX] = {"^EOD", "^EOC", "^EOA", "^EOB", "q", " "};

    for (int i = 0; KEYS_MAX > i; ++i)
        debug->keys[i] = def_keys[i];
    if (NULL != infos[0])
        debug->level = my_getnbr(infos[0]);
    for (int i = 0; KEYS_MAX + 1 > i; ++i)
        if (NULL != infos[i + 1])
            debug->keys[i] = infos[i + 1];
    if (NULL != infos[ARGS_MAX - 2])
        debug->without_next = '0';
    if (NULL != infos[ARGS_MAX - 1])
        debug->debug = '0';
    fill_map_in_debug(debug);
}

static void fill_an_arg(arg_t *arg, char opt, int i)
{
    arg->lname = opts[i].name;
    arg->val = opt;
    if ('w' != opt && 'D' != opt && 'W' != opt && 'B' != opt)
        arg->optarg = optarg;
    else
        arg->optarg = NULL;
}

arg_t *create_an_arg(int val)
{
    arg_t *arg = malloc(sizeof(arg_t));
    char *sopts = "LlrtdqpwD";
    char *lopts = "ngRTbQPWBm";

    if (NULL == arg)
        return (NULL);
    for (int i = 0; (ARGS_MAX - 1) > i; ++i)
        if (val == sopts[i] || val == lopts[i])
            fill_an_arg(arg, sopts[i], i);
    if ('m' == val) {
        arg->lname = opts[9].name;
        arg->val = 'm';
        arg->optarg = optarg;
    }
    return (arg);
}

debug_t *init_debug(void)
{
    debug_t *debug = malloc(sizeof(debug_t));

    if (NULL == debug)
        return (NULL);
    debug->level = 1;
    for (int i = 0; ARGS_MAX > i; ++i)
        debug->infos[i] = NULL;
    debug->map_size[0] = 20;
    debug->map_size[1] = 10;
    debug->without_next = '1';
    debug->debug = '1';
    debug->template = malloc(sizeof(tetrimino_t *) * 1);
    if (NULL == debug->template)
        return (NULL);
    debug->template[0] = NULL;
    return (debug);
}
