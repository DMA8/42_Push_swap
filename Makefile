SRC		= 	push_swap.c \
			list_funcs.c \
			stack_init.c \
			stack_swaps.c \
			sort.c \
			ft_spilt.c \
			sort_3elem.c \
			validation/validation.c \
			validation/utils.c \
			validation/validation_utils.c \

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
