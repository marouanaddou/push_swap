NAME = push_swap
NAME_BONUS = checker
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
SRC = 	operation.c    operation_utils.c \
	  	push_sort.c    push_sort_utils.c push_sort_utils2.c \
	  	push_sort_other.c push_swap_errur_utils.c push_swap_errur.c \
	  	push_swap.c libft.c push_sort_square.c 

SRC_BONUS =	get_next_line.c get_next_line_utils.c checker.c \
			operation_utils_bonus.c operation_bonus.c libft_bonus.c \
			push_errur.c push_errur_utils.c checker_utils.c checker_utils1.c
OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
%.o : %.c push_swap.h 
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS) : $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $@

clean :
	@$(RM) $(OBJ) $(OBJ_BONUS)
fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS)
re : fclean all
.PHONY : all fclean clean re 
