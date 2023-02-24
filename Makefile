SRCS	= main.c moves.c moves_1.c moves_2.c checkers.c algorithm.c hardcode.c lists_1.c move_functions.c utils.c lists.c

OBJS	= $(addprefix objs/,$(SRCS:.c=.o))

CFLAGS	= -Wall -Wextra -Werror -g

RM		= rm -f

NAME	= push_swap

all:		$(NAME)

objs/%.o: srcs/%.c
			@mkdir -p objs
			@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): 	$(OBJS)
			@cc $(OBJS) $(CFLAGS) -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
