SRCS	= main.c moves.c

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
