/*
** EPITECH PROJECT, 2019
** my_rand
** File description:
** Return a random value.
*/

#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"

static int get_a_random_value(int min, int *tab)
{
    int valid_rd = '1';
    int index = 0;
    int nb = 0;

    while ('1' == valid_rd) {
        index = (int)(rand() / (double)RAND_MAX * 21);
        nb = tab[index];
        if (min <= nb)
            valid_rd = '0';
    }
    return (nb);
}

char my_rand(int *rdnb, int min, int limit)
{
    int *tab = malloc(sizeof(int) * 21);
    static int first = 0;

    if (NULL == tab)
        return ('1');
    if (0 == first) {
        srand(time(NULL));
        first = 1;
    }
    for (int i = 0; 21 > i; ++i)
        tab[i] = (int)(rand() / (double)RAND_MAX * (limit + 1));
    *rdnb = get_a_random_value(min, tab);
    free(tab);
    return ('0');
}
