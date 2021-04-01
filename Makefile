##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Make file
##

SRC = 						\
	src/main.c				\
	src/sokoban.c			\
	src/mouvment.c			\
	src/init.c				\
	src/get_map.c			\
	src/display.c			\
	src/win_detection.c		\
	src/loose_detection.c	\
	src/errors_handling.c	\
	src/loop.c


SRC_TEST =					\


TEST =						\


INCLUDE = -I include/

LIB = -L lib/my/ -lmy -lncurses

FLAGS = -Wall -ggdb

NAME = my_sokoban

all:
	(cd lib/my && make && cd ../../)
	gcc -o $(NAME) $(SRC) $(INCLUDE) $(LIB) $(FLAGS)
clean:
	rm -f $(NAME)
	find -type f \( -name '*~' -or -name '#*#' \) -delete
	find -type f \( -name '*.gcda' -or -name '*.gcno' \) -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	all
	find -type f \( -name '*.gcda' -or -name '*.gcno' \) -delete
	gcc -o unit_tests $(SRC_TEST) $(TEST) --coverage -lcriterion $(INCLUDE) $(LIB) $(FLAGS)
	./unit_tests