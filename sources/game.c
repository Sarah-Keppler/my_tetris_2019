/*
** EPITECH PROJECT, 2019
** game
** File description:
** Create the structure of Tetris.
*/

#include <stdlib.h>
#include <stddef.h>
#include "tetris.h"

static void fill_a_line(char *ln, int w, char spe, char def)
{
    for (int i = 0; w > i; ++i)
        ln[i] = def;
    ln[0] = spe;
    ln[my_strlen(ln) - 1] = spe;
}

static char **create_a_board(int h, int w)
{
    char **board = malloc(sizeof(char *) * (h + 1));

    if (NULL == board)
        return (NULL);
    for (int i = 0; h > i; ++i) {
        board[i] = malloc(sizeof(char) * (w + 1));
        if (NULL == board[i])
            return (NULL);
        board[i][w] = '\0';
        fill_a_line(board[i], w, '|', ' ');
    }
    fill_a_line(board[0], w, '+', '-');
    fill_a_line(board[h - 1], w, '+', '-');
    board[h] = NULL;
    return (board);
}

static board_t *init_board(game_t *game, int height, int width)
{
    board_t *board = malloc(sizeof(board_t));

    if (NULL == board)
        return (NULL);
    board->block_map = create_a_board(height + 1, width + 1);
    board->speed = 0.25;
    board->position[0] = 1;
    board->position[1] = 1;
    board->current_tetri = get_the_next_tetri(game);
    board->next_tetri = get_the_next_tetri(game);
    if (NULL == board->block_map || NULL == board->next_tetri ||
        NULL == board->current_tetri)
        return (NULL);
    return (board);
}

tetrimino_t **update_template(tetrimino_t **template)
{
    tetrimino_t **new = NULL;
    int i = 0;

    for (int s = 0; template[s]; ++s)
        if (0 == template[s]->check)
            ++i;
    new = malloc(sizeof(tetrimino_t *) * (i + 1));
    if (NULL == new)
        return (NULL);
    i = 0;
    for (int s = 0; template[s]; ++s)
        if (0 == template[s]->check) {
            new[i] = template[s];
            ++i;
        }
    free(template);
    new[i] = NULL;
    return (new);
}

game_t *init_game(debug_t *debug)
{
    game_t *game = malloc(sizeof(game_t));

    if (NULL == game)
        return (NULL);
    game->template = update_template(debug->template);
    game->keys = debug->keys;
    if (NULL == game->template)
        return (NULL);
    game->size[0] = debug->map_size[0];
    game->size[1] = debug->map_size[1];
    game->high_score = 0;
    game->score = 0;
    game->lines = 0;
    game->level = debug->level;
    game->next = debug->without_next;
    game->board = init_board(game, game->size[0], game->size[1]);
    if (NULL == game->board)
        return (NULL);
    return (game);
}
