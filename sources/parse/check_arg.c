/*
** EPITECH PROJECT, 2019
** check_arg
** File description:
** Check if an arg have a good format.
*/

#include <stdlib.h>
#include <stdio.h>
#include "tetris.h"

static char check_level_arg(arg_t *arg)
{
    if ('L' != arg->val)
        return ('0');
    for (int i = 0; arg->optarg[i]; ++i)
        if (!('0' <= arg->optarg[i] && '9' >= arg->optarg[i])) {
            my_puterror("Error: level argument invalid format\n");
            return ('1');
        }
    return ('0');
}

static char check_map_arg(arg_t *arg)
{
    int nbr = 0;

    if ('m' != arg->val)
        return ('0');
    for (int i = 0; arg->optarg[i]; ++i) {
        if (!('0' <= arg->optarg[i] && '9' >= arg->optarg[i]) &&
            ',' != arg->optarg[i])
            return ('1');
        if (',' == arg->optarg[i])
            ++nbr;
    }
    if (1 != nbr)
        return ('1');
    return ('0');
}

char check_an_arg(arg_t *arg)
{
    if ('1' == check_map_arg(arg)) {
        my_puterror("Error: --map-size= invalid format\n");
        return ('1');
    }
    if ('1' == check_level_arg(arg))
        return ('1');
    return ('0');
}
