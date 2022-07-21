SRCS	= ft_printf.c ft_printf_utils.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= cc
RM			= rm -f
AR			= ar rc

CFLAGS	= -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
