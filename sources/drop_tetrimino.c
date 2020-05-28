/*
** EPITECH PROJECT, 2019
** drop_tetrimino
** File description:
** Drop the tetrimino.
*/

#include "tetris.h"

static void clear_behind_plus(board_t *board)
{
    tetrimino_t *current = board->current_tetri;
    int y = -1;

    while (current->design[++y]);
    if (1 > y)
        return;
    y = my_strlen(current->design[0]);
    if (y >= my_strlen(current->design[1]))
        return;
    for (int s = y - 1; current->design[1][s]; ++s)
        if ('*' == current->design[1][s])
            board->block_map[board->position[0]][board->position[1] + s] = ' ';
    return;
}

static void move_down_a_tetrimino(game_t *game)
{
    board_t *board = game->board;
    tetrimino_t *current = board->current_tetri;
    int lines = 0;
    int cols = 0;

    for (int i = 0; board->current_tetri->design[i]; ++i)
        for (int y = 0; board->current_tetri->design[i][y]; ++y) {
            lines = i + board->position[0];
            cols = y + board->position[1];
            board->block_map[lines][cols] = board->current_tetri->design[i][y];
        }
    if (1 == board->position[0])
        return;
    for (int y = 0; current->design[0][y]; ++y) {
        cols = y + board->position[1];
        if (' ' != current->design[0][y])
            board->block_map[board->position[0] - 1][cols] = ' ';
        else
            clear_behind_plus(board);
    }
}

static char check_if_can_drop(game_t *game)
{
    board_t *board = game->board;
    int next_position = board->position[0] + board->current_tetri->size[0];
    int cols = 0;
    int line = -1;
    char board_char = '*';
    char tetri_char = '*';

    while (board->block_map[++line]);
    if (next_position == (line - 1))
        return ('1');
    line = -1;
    while (board->current_tetri->design[++line]);
    for (int y = 0; board->current_tetri->design[line - 1][y]; ++y) {
        cols = y + board->position[1];
        board_char = board->block_map[next_position][cols];
        tetri_char = board->current_tetri->design[line - 1][cols];
        if ('*' == board_char && '*' == tetri_char)
            return ('1');
    }
    return ('0');
}

char drop_a_tetrimino(game_t *game, board_t *board)
{
    if (0 == board->position[0] && 0 == board->position[1]) {
        board->position[0] = 1;
        board->position[1] = 1;
    }
    if ('0' == check_if_can_drop(game)) {
        move_down_a_tetrimino(game);
        ++board->position[0];
    } else
        return ('1');
    return ('0');
}
