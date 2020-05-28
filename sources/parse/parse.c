/*
** EPITECH PROJECT, 2019
** parse
** File description:
** Parse the options of tetris with getopt().
*/

#include <stdlib.h>
#include <stdio.h>
#include "tetris.h"
#include "opt.h"

static char *add_optarg(char const *arg)
{
    char *new = malloc(sizeof(char) * (my_strlen(arg) + 1));

    if (NULL == new)
        return (NULL);
    my_strcpy(new, arg);
    return (new);
}

static void add_level_key_infos(char **infos, arg_t *arg, int i)
{
    char *spe[4] = {"left_arrow", "right_arrow", "up_arrow", "down_arrow"};
    char *ref[4] = {"^EOD", "^EOC", "^EOA", "^EOB"};

    if ('L' == arg->val) {
        infos[0] = add_optarg(arg->optarg);
        return;
    }
    for (int s = 0; 4 > s; ++s)
        if (0 == my_strcmp(spe[s], arg->optarg)) {
            infos[i] = add_optarg(ref[s]);
            return;
        }
    infos[i] = add_optarg(arg->optarg);
}

static char add_infos(debug_t *debug, arg_t *arg)
{
    char *sopts = "LlrtdqpmwD";
    int i = -1;

    while (arg->val != sopts[++i]);
    if (NULL != debug->infos[i]) {
        my_puterror("Error: Argument already been set\n");
        return ('1');
    }
    if ('w' == arg->val || 'D' == arg->val) {
        debug->infos[i] = "0";
        return ('0');
    }
    add_level_key_infos(debug->infos, arg, i);
    if (NULL == debug->infos[i])
        return ('1');
    return ('0');
}

char parse_opts(int ac, char **av, debug_t *debug)
{
    char *optstr = "L:l:r:t:d:q:p:wDngRTbQPmWB";
    int option_index = 0;
    int val = -1;
    arg_t *arg = NULL;

    val = getopt_long(ac, av, optstr, opts, &option_index);
    while (EOF != val && -1 != val) {
        if ('?' == val) {
            my_puterror("Error: Invalid argument\n");
            return ('1');
        }
        arg = create_an_arg(val);
        if (NULL == arg)
            return ('1');
        if ('1' == check_an_arg(arg) || '1' == add_infos(debug, arg))
            return ('1');
        val = getopt_long(ac, av, optstr, opts, &option_index);
        free(arg);
    }
    return ('0');
}
