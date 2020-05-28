/*
** EPITECH PROJECT, 2019
** opt.h
** File description:
** Struct option.
*/

#include <getopt.h>
#include <stddef.h>

static struct option opts[] =
{
    {"level=", required_argument, NULL, 'n'},
    {"key-left=", required_argument, NULL, 'g'},
    {"key-right=", required_argument, NULL, 'R'},
    {"key-turn=", required_argument, NULL, 'T'},
    {"key-drop=", required_argument, NULL, 'b'},
    {"key-quit=", required_argument, NULL, 'Q'},
    {"key-pause=", required_argument, NULL, 'P'},
    {"without-next", no_argument, NULL, 'W'},
    {"debug", no_argument, NULL, 'B'},
    {"map-size=", required_argument, NULL, 'm'},
    {0, 0, 0, 0},
};
