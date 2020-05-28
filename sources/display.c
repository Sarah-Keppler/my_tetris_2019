/*
** EPITECH PROJECT, 2019
** display
** File description:
** Display the game.
*/

#include <stddef.h>
#include <stdlib.h>
#include <ncurses.h>
#include "tetris.h"

static void display_the_next_tetri(game_t *game)
{
    board_t *board = game->board;
    int row = -(board->next_tetri->size[0] / 2);
    int cols = ((game->size[1] / 2) + 5);

    if ('0' == game->next)
        return;
    for (int i = 0; board->next_tetri->design[i]; ++i) {
        move(LINES / 2 + row, COLS / 2 + cols);
        printw(board->next_tetri->design[i]);
        ++row;
    }
}

static void display_the_board(game_t *game)
{
    int row = -(game->size[0] / 2);
    int cols = -(game->size[1] / 2);

    for (int i = 0; (game->size[0] + 1) > i; ++i) {
        move(LINES / 2 + row, COLS / 2 + cols);
        printw(game->board->block_map[i]);
        ++row;
    }
}

static char display_infos_and_numbers(char *info, int number)
{
    char *info_wth_spaces = malloc(sizeof(char) * (15 + 1));
    char *str = malloc(sizeof(char) * (get_nb_of_digits(number) + 1));

    if (NULL == str || NULL == info_wth_spaces)
        return ('1');
    my_int_to_str(number, str);
    my_strcpy(info_wth_spaces, info);
    for (int i = my_strlen(info); 15 > i; ++i)
        info_wth_spaces[i] = ' ';
    info_wth_spaces[15] = '\0';
    printw(info_wth_spaces);
    printw(str);
    free(info_wth_spaces);
    free(str);
    return ('0');
}

static char display_informations(game_t *game)
{
    int lines = -3;
    char *info_board[5] = {"High Score:", "Score:", "\n", "Lines:", "Level:"};
    int number_board[5] = {game->high_score, game->score, 0, game->lines,
        game->level};

    for (int i = 0; 5 > i; ++i) {
        if (0 == my_strcmp(info_board[i], "\n")) {
            ++lines;
            continue;
        }
        move(LINES / 2 + lines, 0);
        if ('1' == display_infos_and_numbers(info_board[i], number_board[i]))
            return ('1');
        ++lines;
    }
    return ('0');
}

char display_the_game(game_t *game)
{
    if ('1' == display_informations(game))
        return ('1');
    display_the_board(game);
    display_the_next_tetri(game);
    return ('0');
}
