SRCS 			= main.c 

OBJS			= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAG) -I/usr/include -Imlx_linux -O3 -c $< -o $@

	
NAME  		= fractol
MLX   	= ./mlx_linux/libmlx_Linux.a
MLX_DIR = ./mlx_linux

INC				= -I. -I$(MLX_DIR)

CC				= cc
CFLAG			= -Wall -Wextra -Werror -g3
RM				= rm -f

ifeq ($(DEBUG), 1)
	D_FLAG = -g
endif


all:			$(NAME)

$(NAME):	$(OBJS) $(MLX)
	 #$(CC)  $(CFLAG) $(SRCS) $(MLX) $(INC) -o $(NAME)
	 $(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	 printf "Compiled.\n"

$(MLX):
	 $(MAKE) DEBUG=$(DEBUG) -s -C $(MLX_DIR)

clean: 
	 $(RM) $(OBJS)
	 $(MAKE) -s clean -C $(MLX_DIR)

fclean: clean
	 $(RM) $(NAME)
	 #$(MAKE) -s fclean -C $(MLX_DIR)

re: fclean all

.SILENT:

.PHONY: all clean fclean re
