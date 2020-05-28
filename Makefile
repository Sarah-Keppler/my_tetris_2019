##
## EPITECH PROJECT, 2019
## Tetris
## File description:
## Makefile from Lucas Marsala from Kevin Spegt
##
## --------------------------------------------------------------- ##
NAME	=	tetris

## --------------------------------------------------------------- ##
PATH_LIB	=	./lib/my/
LIB	=	get_next_line.c         \
                my_math.c               \
                my_rand.c               \
                my_read.c               \
                my_strcat.c             \
                my_strcmp.c             \
                my_strcpy.c             \
                my_str_is.c             \
		my_str_to_word_array.c  \
                my_swaps.c              \
                my_write.c              \
                my_write_number.c       \
                number.c                \
                str_manipulation.c      \
                tab_and_spaces.c

## --------------------------------------------------------------- ##
PATH_PARSE	=	./sources/parse/
PARSE	=	debug.c			\
		parse.c			\
		print_debug.c		\
		read_tetriminos.c	\
		tetriminos.c		\
		check_tetrimino.c	\
		print_tetrimino.c	\
		print_help.c		\
		check_arg.c

## --------------------------------------------------------------- ##
PATH_GAME	=	./sources/
GAME	=	main.c			\
		game.c			\
		display.c		\
		drop_tetrimino.c	\
		game_features.c		\
		generate_a_new_block.c	\
		move_left.c		\
		move_right.c

## --------------------------------------------------------------- ##
SRC	=	$(addprefix $(PATH_LIB), $(LIB))	\
		$(addprefix $(PATH_PARSE), $(PARSE))	\
		$(addprefix $(PATH_GAME), $(GAME))

## --------------------------------------------------------------- ##
REDDARK	=	\033[31;1m
REDDARK =       \033[31;1m
RED     =       \033[31;1m
GREEN   =       \033[32;1m
YEL     =       \033[33;1m
BLUE    =       \033[34;1m
PINK    =       \033[35;1m
CYAN    =       \033[36;1m
WHITE   =       \033[0m

## --------------------------------------------------------------- ##
OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-g		\
		-W		\
		-Wall		\
		-Wextra		\
		-Werror		\
		-pedantic	\
		-I./include/

## --------------------------------------------------------------- ##
all:	$(NAME)
	@printf	"$(GREEN)\n$(WHITE)"
	@printf "$(GREEN)  [$(WHITE)$(NAME)$(GREEN)] -> "
	@printf "$(WHITE)Compilation terminée."
	@printf "$ Binaire : $(CYAN) ./%s$(WHITE)\n\n" $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

## --------------------------------------------------------------- ##
clean:
	rm -f $(OBJ)
	@printf "$(GREEN)\n$(WHITE)"
	@printf "$(GREEN)  [$(WHITE)$(NAME)$(GREEN)] -> "
	@printf "$(WHITE)Suppression terminée.\n\n"

pizza:
	rm -f *~
	rm -f vgcore.*

fclean:	pizza clean
	rm -f $(NAME)

re:	fclean all

.PHONY: re clean fclean all pizza

## ========================================================================= ##
%.o:    %.c
	@printf "$(GREEN)[$(WHITE)$(NAME)$(GREEN)] — $(WHITE)%-45s\n" $<
	@printf "$(GREEN) → $(RES) %-50s" $@
	@printf "$(GREEN)[$(WHITE)√$(GREEN)]\n\n"
	@gcc $(CFLAGS) -o $@ -c $<
