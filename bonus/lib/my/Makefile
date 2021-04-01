##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Make file
##

SRC =					\
	my_putchar.c		\
	my_getnbr.c				\
	my_put_nbr.c			\
	my_putstr.c				\
	my_printf.c 			\
	my_put_cap_hex.c 		\
	my_put_float.c 			\
	my_put_hex.c 			\
	my_put_oct.c 			\
	my_strlen.c				\
	my_strcpy.c				\
	my_strcmp.c				\
	my_str_to_words_array.c	\
	my_strcat.c			\

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm *.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
