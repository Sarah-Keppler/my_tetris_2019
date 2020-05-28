/*
** EPITECH PROJECT, 2019
** drop_tetrimino
** File description:
** Drop the tetrimino.
*/

#include "tetris.h"

static char check_if_can_move_right(board_t *board)
{
    tetrimino_t *current = board->current_tetri;
    int next = -1;
    int max = -1;
    int lines = -1;
    char tetri = '0';
    char block = ' ';

    while (board->block_map[0][++max]);
    for (int i = 0; current->design[i]; ++i) {
        next = board->position[1] + my_strlen(current->design[i]);
        lines = i + board->position[0];
        if (next == (max - 1))
            return ('1');
        tetri = current->design[i][my_strlen(current->design[i]) - 1];
        block = board->block_map[lines][next];
        if ('*' == tetri && '*' == block)
            return ('1');
    }
    return ('0');
}

static void move_without_destroy_others(board_t *board, int i, int y)
{
    tetrimino_t *current = board->current_tetri;
    int lines = i + board->position[0];
    int cols = i + board->position[1];
    int next = board->position[1] + my_strlen(current->design[i]);

    if ((cols + 1) != next) {
        board->block_map[lines][cols + 1] = current->design[i][y];
        return;
    }
    if (' ' == current->design[i][y] &&
        '*' == board->block_map[lines][cols + 1])
        board->block_map[lines][cols + 1] = '*';
    board->block_map[lines][cols + 1] = current->design[i][y];
}

static void move_right_a_tetri(board_t *board)
{
    tetrimino_t *current = board->current_tetri;
    int lines = -1;

    for (int i = 0; current->design[i]; ++i)
        for (int y = 0; current->design[i][y]; ++y)
            move_without_destroy_others(board, i, y);
    if (1 == board->position[1])
        return;
    for (int i = 0; current->design[i]; ++i) {
        lines = board->position[0] + i;
        board->block_map[lines][board->position[1]] = ' ';
    }
}

void move_right(game_t *game)
{
    if ('1' == check_if_can_move_right(game->board))
        return;
    move_right_a_tetri(game->board);
    ++game->board->position[1];
}
