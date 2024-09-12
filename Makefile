NAME = philosophers

SRC	=  main.c \
	parsing.c \
	initialize.c \

CC = cc
CFLAGS = -pthread -g -Wall -Werror -Wextra 
OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) -o $@ $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re