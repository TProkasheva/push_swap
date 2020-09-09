NAME1 = checker
NAME2 = push_swap

LIBFT = ./libft/libft.a

SRC1 = 	checker.c\

SRC2 =	push_swap.c\
		sort_funcs.c\
		sort_misc_funcs.c\
		hardcoded_algo.c

SRC3 = 	array_funcs.c\
		rotate_push.c\
		other_stack_funcs.c\
		read_funcs.c\
		freeall.c\
		swap.c\
		write_stacks.c\
		write_bonus.c

OBJ1 = $(patsubst %.c, %.o, $(SRC1))
OBJ2 = $(patsubst %.c, %.o, $(SRC2))
OBJ3 = $(patsubst %.c, %.o, $(SRC3))

CFLAGS = -Wall -Wextra -Werror
INCLUDES = push_swap.h
NAME = $(NAME1) $(NAME2)

all: $(NAME)

$(LIBFT):
	$(MAKE) -sC libft all

$(NAME1): $(OBJ1) $(OBJ3)
	gcc $(CFLAGS) -o $(NAME1) $(OBJ1) $(OBJ3) $(LIBFT)

$(NAME2): $(OBJ2) $(OBJ3)
	gcc $(CFLAGS) -o $(NAME2) $(OBJ2) $(OBJ3) $(LIBFT)

%.o: %.c $(INCLUDES) $(LIBFT)
	gcc -I . $(CFLAGS) -c $< -o $@

norm:
	norminette **

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) && $(MAKE) clean -C ./libft

fclean:clean
	rm -f $(NAME1) $(NAME2) && $(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all norm clean fclean re
