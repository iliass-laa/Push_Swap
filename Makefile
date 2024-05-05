CC = cc
CFILES = parse_split.c parse.c push_swap.c utils1.c utils2.c helper.c
OBJ = $(CFILES:.c=.o)
NAME = push_swap

all : $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re