/*
** EPITECH PROJECT, 2019
** drop_tetrimino
** File description:
** Drop the tetrimino.
*/

#include "tetris.h"

static char check_if_can_move_left(board_t *board)
{
    tetrimino_t *current = board->current_tetri;
    int cols = -1;
    char tetri = ';';
    char block = 'b';

    if (1 == board->position[1])
        return ('1');
    for (int i = 0; current->design[i]; ++i) {
        cols = board->position[1] - 1;
        tetri = current->design[i][0];
        block = board->block_map[board->position[0] + i][cols];
        if ('*' == block && '*' == tetri)
            return ('1');
    }
    return ('0');
}

static void move_without_destroy_others(board_t *board, int i, int y)
{
    tetrimino_t *current = board->current_tetri;
    int lines = i + board->position[0];
    int cols = i + board->position[1];
    int next = board->position[1] - 1;

    if ((cols - 1) != next) {
        board->block_map[lines][cols - 1] = current->design[i][y];
        return;
    }
    if (' ' == current->design[i][y] &&
        '*' == board->block_map[lines][cols - 1])
        board->block_map[lines][cols - 1] = '*';
    board->block_map[lines][cols - 1] = current->design[i][y];
}

static void move_left_a_tetri(board_t *board)
{
    tetrimino_t *current = board->current_tetri;
    int lines = -1;
    int cols = -1;

    for (int i = 0; current->design[i]; ++i)
        for (int y = 0; current->design[i][y]; ++y)
            move_without_destroy_others(board, i, y);
    for (int i = 0; current->design[i]; ++i) {
        lines = board->position[0] + i;
        cols = board->position[1] + my_strlen(current->design[i]) - 1;
        board->block_map[lines][cols] = ' ';
    }
}

void move_left(game_t *game)
{
    if ('1' == check_if_can_move_left(game->board))
        return;
    move_left_a_tetri(game->board);
    --game->board->position[1];
}
