SRC		= 	push_swap.c \
			utils.c \
			list_funcs.c \
			validation.c \
			validation_utils.c \
			stack_init.c \
			stack_swaps.c \

OBJ = $(SRC:.c=.o)

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) push_swap.h
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
