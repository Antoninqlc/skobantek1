##
## EPITECH PROJECT, 2021
## make
## File description:
## makefile
##

SOURCES		=	sokoban.c					\
				./utils/my_strlen.c 		\
				./utils/game.c 				\
				./utils/map_move.c 			\
				./utils/map_move_disp.c 	\
				./utils/get_pos.c 			\
				./utils/check_hole.c 		\
				./utils/my_strcomp.c 		\
				./utils/my_putstr.c 		\
				./utils/my_stwa.c 			\
				./utils/modif_map.c 		\

NAME		=	my_sokoban

CFLAGS		=	-Wall -Wextra -lncurses

OBJECTS		=	$(SOURCES:.c=.o)

all:  $(NAME)

$(NAME):   $(OBJECTS)
	gcc -o $(NAME) $(OBJECTS) $(CFLAGS)

clean:
	rm -f $(OBJECTS)
	rm -f *~
	rm -f *.tmp
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
