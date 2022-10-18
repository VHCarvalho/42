SRCS 			= push_swap.c

OBJS			= $(SRCS:.c=.o)
	
NAME  		= push_swap
LIBFT   	= ./libft/libft.a
LIBFT_DIR = ./libft

INC				= -I. -I$(LIBFT_DIR)

CC				= gcc
CFLAG			= -Wall -Wextra -Werror
RM				= rm -f

all:			$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	 $(CC) $(CFLAG) $(SRCS) $(LIBFT) $(INC) -o $(NAME)
	 printf "Compiled.\n"

$(LIBFT):
	 $(MAKE) -s -C $(LIBFT_DIR)

clean: 
	 $(RM) $(OBJS)
	 $(MAKE) -s clean -C $(LIBFT_DIR)

fclean: clean
	 $(RM) $(NAME)
	 $(MAKE) -s fclean -C $(LIBFT_DIR)

re: fclean all

.SILENT:

.PHONY: all clean fclean re
