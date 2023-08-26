##
## EPITECH PROJECT, 2023
## B-AIA-200-LYN-2-1-n4s-elias.abassi
## File description:
## Makefile
##

SRC	=	main.c	\
		parse_lidar.c	\
		clean_lidar.c	\
		algo.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	 ai

CFLAGS = -g3

all:	$(NAME)

$(NAME):
		cd ../..
		gcc $(SRC) -o $(NAME) -I./include $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY	:	all clean fclean re
