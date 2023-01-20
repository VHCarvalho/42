SRCS 			= main.c 

OBJS			= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

NAME  		= fractol

CC				= cc
CFLAG			= -Wall -Wextra -Werror -g3
RM				= rm -f

ifeq ($(DEBUG), 1)
	D_FLAG = -g
endif

UNAME	:= $(shell uname)

ifeq ($(UNAME), Linux)
    OFLAGS    = $(CFLAG) -L ./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux \
              -lXext -lX11 -lm -lz
    MLX        = ./mlx_linux
else
    OFLAGS    = $(CFLAG) -L ./mlx -lmlx -framework OpenGL -framework AppKit
    MLX        = ./mlx
endif

all:			$(NAME)

$(NAME):	$(OBJS)
	 printf "Compiling...\n"
	 make -C $(MLX)
	 $(CC) $(OBJS) $(OFLAGS) -o $@
	 printf "Compiled.\n"


clean: 
	 $(RM) $(OBJS)
	 $(MAKE) -s clean -C $(MLX)
	 printf "Cleaning done.\n"

fclean: clean
	 $(RM) $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re
