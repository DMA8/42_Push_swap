SRC			=	list_funcs.c \
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
				small_utils.c \
				get_node.c \
				scoring.c \
				scoring2.c \
				free_memory.c \

SRC_B		=	$(SRC) bonus/check_instructions_bonus.c \
				bonus/push_swap_checker_bonus.c \
				bonus/gnl/get_next_line_utils.c \
				bonus/gnl/get_next_line.c \

SRC_MAIN	=	push_swap.c $(SRC)

OBJ			=	$(SRC:.c=.o)
OBJ_B		=	$(SRC_B:.c=.o)
OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

NAME		=	push_swap
BONUS_NAME	=	checker
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
HEADER		=	push_swap.h
HEADER_B	=	bonus/push_swap_bonus.h
H_GNL_B		=	bonus/gnl/get_next_line.h

all:			$(NAME)

$(NAME):		$(OBJ_MAIN)
				@$(CC) $(CFLAGS) $(OBJ_MAIN) -o $(NAME)

bonus:			$(OBJ_B)
				@$(CC) $(CFLAGS) $(OBJ_B) -o $(BONUS_NAME)

clean:
				rm -f $(OBJ_MAIN) $(OBJ_B) $(OBJ)

fclean:			clean
				rm -f $(NAME) $(BONUS_NAME)

$(OBJ):			$(HEADER)
$(OBJ_MAIN):	$(HEADER)
$(OBJ_B):		$(HEADER) $(HEADER_B) $(H_GNL_B)

re:				fclean all

.PHONY: 		all clean fclean re
