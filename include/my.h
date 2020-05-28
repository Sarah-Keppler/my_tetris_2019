/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** My lib.
*/

#ifndef MY_H_
#define MY_H_

#include "get_next_line.h"

int get_nb_of_digits(int);

void my_int_to_str(int, char *);

char *get_next_line(int);

int my_pow(int, int);
int my_getnbr(char const *);

char my_rand(int *, int, int);

char *read_a_file_with_stat(char *);
char *read_a_file(int, int);

void my_putchar(char const);
void my_putstr(char const *);
void my_write(char const *);
void my_puterror(char const *);

void my_put_nbr(int);

void my_strcpy(char *, char const *);
void my_strncpy(char *, char const *, int);

void my_strcat(char *, char const *);
char *my_strcat_malloc(char *, char const *);

char my_str_isnum(char const *);
char my_str_isnum_with_neg(char const *);
char my_str_isint_float(char const *);

char **my_str_to_word_array(char *, char);

int my_strlen(char const *);
void my_revstr(char *);
char *my_strstr(char *, char const *);

int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);

void my_swap(int *, int *);
void my_swap_char(char *, char *);

char *remove_space_and_tab(char const *);



#endif /* MY_H_ */
