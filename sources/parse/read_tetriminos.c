/*
** EPITECH PROJECT, 2019
** read_tetrimino
** File description:
** Parse each tetriminos.
*/

#include <dirent.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

static char *open_file(char *name)
{
    int fd = 0;
    int len = my_strlen(PATH_TETRIMINO) + my_strlen(name);
    char *buf = NULL;

    buf = malloc(sizeof(char) * (len + 1));
    if (NULL == buf)
        return (NULL);
    my_strcpy(buf, PATH_TETRIMINO);
    my_strcat(buf, name);
    fd = open(buf, O_RDONLY);
    if (-1 == fd)
        return (NULL);
    free(buf);
    buf = read_a_file(fd, 20);
    if (NULL == buf)
        return (NULL);
    close(fd);
    return (buf);
}

static char init_tetrimino(char *name, debug_t *debug)
{
    char *file = open_file(name);

    if (NULL == file)
        return ('1');
    if ('\n' == file[my_strlen(file) - 1])
        file[my_strlen(file) - 1] = '\0';
    debug->buf = my_str_to_word_array(file, '\n');
    if (NULL == debug->buf)
        return ('1');
    free(file);
    return ('0');
}

static char update_tetrimino(struct dirent *rd_file, tetrimino_t *tetri,
    debug_t *debug)
{
    if ('1' == init_tetrimino(rd_file->d_name, debug))
        return ('1');
    check_a_tetrimino(tetri, debug->buf);
    if ('1' == fill_a_tetrimino(tetri, debug->buf) ||
        '1' == add_a_template(debug, tetri))
        return ('1');
    for (int i = 0; debug->buf[i]; ++i)
        free(debug->buf[i]);
    free(debug->buf);
    return ('0');
}

static char get_tetrimino(struct dirent *rd_file, debug_t *debug)
{
    tetrimino_t *tetrimino = create_a_tetrimino(rd_file->d_name);
    char type = '3';

    if (NULL == tetrimino)
        return ('1');
    type = check_tetrimino_file(rd_file->d_name);
    if ('1' == type) {
        tetrimino->check = 1;
        if ('1' == add_a_template(debug, tetrimino))
            return ('1');
        return ('0');
    }
    if ('1' == update_tetrimino(rd_file, tetrimino, debug))
        return ('1');
    return ('0');
}

char read_each_tetriminos(debug_t *debug)
{
    DIR *dir = opendir(PATH_TETRIMINO);
    struct dirent *rd_file = {0};

    if (NULL == dir) {
        my_puterror("The directory ""tetriminos/"" doesn't exist.\n");
        return ('1');
    }
    rd_file = readdir(dir);
    if (NULL == rd_file) {
        my_puterror("No file in tetriminos/.\n");
        return ('1');
    }
    while (NULL != rd_file) {
        if ('.' != rd_file->d_name[0] && '1' == get_tetrimino(rd_file, debug))
            return ('1');
        rd_file = readdir(dir);
    }
    closedir(dir);
    return ('0');
}
