SRCS			= ft_printf ft_putaddress ft_putchar_fd ft_puthex ft_putnbr_fd ft_putstr_fd ft_strlen \

OBJS			= $(SRCS:=.o)


CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus: 			$(OBJS)
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:					fclean $(NAME)

.PHONY:			all clean fclean re