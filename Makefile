SRCS			=	ft_printf.c ft_putaddress.c ft_putchar_fd.c ft_puthex.c \
					ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c

OBJS			= $(SRCS:.c=.o)


CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:					fclean $(NAME)

.PHONY:			all clean fclean re