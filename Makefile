##
## EPITECH PROJECT, 2022
## B-CPE-100-LIL-1-1-cpoolday10-nicolas1.nguyen
## File description:
## Makefile
##

SRC =		./src/my_sokoban.c 		\
			./src/check_end.c 		\
			./src/movement.c 		\
			./src/get_map.c 		\
			./src/get_storage.c 	\
			./src/get_boxes.c 		\
			./src/error.c 			\
			./src/initialise.c		\
			./src/tools.c 			\
			./src/main.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Werror -Wextra -I./include

CSFML = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

NCURSES = -lncurses

NAME = my_sokoban

$(NAME): $(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy $(NCURSES) -g

all:     $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my/

re:	fclean all

.PHONY: all clean fclean re
