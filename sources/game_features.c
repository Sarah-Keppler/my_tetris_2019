/*
** EPITECH PROJECT, 2019
** game_feature
** File description:
** All game features.
*/

#include <ncurses.h>
#include <time.h>
#include "tetris.h"

char prepare_blocks(game_t *game, board_t *board)
{
    if (NULL != board->current_tetri)
        return ('0');
    board->current_tetri = board->next_tetri;
    board->next_tetri = get_the_next_tetri(game);
    if (NULL == board->next_tetri)
        return ('1');
    board->position[0] = 1;
    board->position[1] = 1;
    return ('0');
}

static char execute_each_seconds(game_t *game, float seconds,
    int *seconds_passed)
{
    if (game->board->speed >= seconds)
        return ('0');
    ++*seconds_passed;
    if ('1' == drop_a_tetrimino(game, game->board)) {
        game->board->current_tetri = NULL;
        if ('1' == prepare_blocks(game, game->board))
            return ('1');
    }
    clear();
    if ('1' == display_the_game(game))
        return ('1');
    refresh();
    return ('0');
}

char game_routine(game_t *game)
{
    float time = 0;
    float seconds = 0;
    int seconds_passed = 0;

    clear();
    if ('1' == display_the_game(game))
        return ('1');
    refresh();
    while (1) {
        time = clock() - time;
        seconds = (float)((((double)time) / CLOCKS_PER_SEC) - seconds_passed);
        prepare_blocks(game, game->board);
        if ('1' == execute_each_seconds(game, seconds, &seconds_passed))
            return ('1');
    }
    return ('0');
}
