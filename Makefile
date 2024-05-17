CFLAGS = -Wall -Wextra -Werror
CC = cc
CFILES = helper.c algo.c parse_split.c parse.c push_swap.c utils1.c utils2.c utils3.c split_helper.c sort_small.c
OBJ = $(CFILES:.c=.o)
NAME = push_swap

all : $(NAME) 

%.o : %.c push_swap.h
	$(CC)  $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) 
	$(CC) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re