CC = cc
CFILES = helper.c algo.c parse_split.c parse.c push_swap.c utils1.c utils2.c
OBJ = $(CFILES:.c=.o)
NAME = push_swap

all : $(NAME) 

%.o : %.c 
	$(CC) -c $< -o $@

$(NAME): $(OBJ) push_swap.h
	$(CC) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re