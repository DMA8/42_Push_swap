SRC		= 	push_swap.c \
			list_funcs.c \
			stack_init.c \
			sort.c \
			sort_3elem.c \
			sort_check.c \
			validation/ft_spilt.c \
			validation/validation.c \
			validation/utils.c \
			validation/validation_utils.c \
			stack_swap_push.c \
			cmd_handler.c \
			stack_rotate.c \
			stack_reverse_rotate.c \
			linked_list_operations.c \

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
