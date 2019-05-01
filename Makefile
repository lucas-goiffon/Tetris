##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Task01 of CPool Day10
##

SRC		=		src/main.c										\
				src/game/completed_lines.c						\
				src/game/displays.c								\
				src/game/displays2.c							\
				src/game/high_score.c							\
				src/game/initializations_info.c					\
				src/game/initializations_game.c					\
				src/game/main.c									\
				src/game/menus.c								\
				src/game/moves.c								\
				src/game/rand_tetri.c							\
				src/game/size_max_tetri.c						\
				src/game/turns.c								\
				src/game/write_buff_game.c						\
				src/initialization/create_rotate_tetri.c		\
				src/initialization/debug.c						\
				src/initialization/flags.c						\
				src/initialization/init_flags.c					\
				src/initialization/linked_lists.c				\
				src/initialization/read_directory.c				\
				src/initialization/sort_alpha_functions.c		\
				src/initialization/sort_alpha.c					\
				src/initialization/test_good_flag.c				\
				src/initialization/verify_tetriminos.c

NAME	=		tetris

GCC		= 		@gcc -o $(NAME) $(SRC) -g3 -Llib/my/. -lmy -lncurses

PROJECT	=		Tetris

SPACES	=		$(shell expr '$(PROJECT)' : '.*')

all:
	@printf "\x1B[1;33mWelcome to $(PROJECT) Project !\x1B[1;0m"
	@sleep 0.5

ifeq ($(shell test -f lib/my/libmy.a ; echo $$?), 1)
	@printf "\x1B[1;34m\rCompiling my lib       %$(SPACES)c\x1B[1;0m" ' '
	@make -sC ./lib/my/
else
	@printf "\x1B[1;31m\rLib already exist      %$(SPACES)c\x1B[1;0m" ' '
	@sleep 0.5
endif

	@printf "\x1B[1;34m\rCompiling Sources Files%$(SPACES)c\x1B[1;0m" ' '
	$(GCC)

	@rm -rf $(NAME).dSYM
	@printf "\x1B[1;32m\rCompilation terminated%$(SPACES)c\n\x1B[1;0m" ' '



clean:
	@rm -f $(OBJ)
	@rm -rf $(NAME).dSYM



fclean: clean
	@printf "\x1B[1;31mCleaning...\n\x1B[1;0m"
	rm -f $(NAME) lib/my/libmy.a



re:		fclean
	@printf "\x1B[1;33mRecompiling...\n\x1B[1;0m"
	@make -sC ./lib/my/
	$(GCC)
	@rm -rf $(NAME).dSYM

auteur:
	echo "Lucas GOIFFON" > Auteur
