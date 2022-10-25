SRCS 			= push_swap.c utils.c test.c sort.c

OBJS			= $(SRCS:.c=.o)
	
NAME  		= push_swap
LIBFT   	= ./libft/libft.a
LIBFT_DIR = ./libft

INC				= -I. -I$(LIBFT_DIR)

CC				= gcc
CFLAG			= -Wall -Wextra -Werror -g3
RM				= rm -f

ifeq ($(DEBUG), 1)
	D_FLAG = -g
endif


all:			$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	 $(CC)  $(CFLAG) $(SRCS) $(LIBFT) $(INC) -o $(NAME)
	 printf "Compiled.\n"

$(LIBFT):
	 $(MAKE) DEBUG=$(DEBUG) -s -C $(LIBFT_DIR)

clean: 
	 $(RM) $(OBJS)
	 $(MAKE) -s clean -C $(LIBFT_DIR)

fclean: clean
	 $(RM) $(NAME)
	 $(MAKE) -s fclean -C $(LIBFT_DIR)

re: fclean all

.SILENT:

.PHONY: all clean fclean re
