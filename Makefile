PROGRAM = push_swap
CC = cc
AR = ar cr
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
SRC = 	operation.c    operation_utils.c \
	  	push_sort.c    push_sort_utils.c push_sort_utils2.c \
	  	push_sort_other.c push_swap_errur_utils.c push_swap_errur.c \
	  	push_swap.c libft.c
OBJ = $(SRC:.c=.o)
NAME = pushswap.a

all : $(NAME) $(PROGRAM)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)
$(PROGRAM) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
%.o : %.c push_swap.h 
	@$(CC) $(CFLAGS) -c $< -o $@
clean :
	@$(RM) $(OBJ)
fclean : clean
	@$(RM) $(NAME) $(PROGRAM)

re : fclean all
.PHONY : all fclean clean re 
