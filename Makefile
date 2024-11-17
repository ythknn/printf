NAME 		= libftprintf.a

SRCS	 	=	ft_printf.c ft_funcs.c

OBJS 		= $(SRCS:.c=.o)

CFLAGS 		= -Wall -Werror -Wextra

$(NAME):	$(OBJS)
			ar -rc $(NAME) $(OBJS) 

all: 		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re: 		fclean all