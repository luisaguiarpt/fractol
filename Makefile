CC=cc
FLAGS=-Wall -Wextra -Werror -g
INCM=mlx
INCL=libft
LIBS=-lmlx -lXext -lX11 -lm

SRCS=calc.c checks.c core.c utils.c fractol.c hooks.c hooks_utils.c \
	 messages.c print.c

OBJS=$(SRCS:%.c=%.o)

MLX=mlx/libmlx.a
LIBFT=libft/libft.a
NAME=fractol

all: $(NAME)

$(NAME): $(OBJS) makelibs
	$(CC) $(FLAGS) $(OBJS) $(MLX) $(LIBFT) -o $@ -I$(INCS) $(LIBS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INCM) -I$(INCL)

makelibs:
	make -C mlx/ all
	make -C libft/ all

clean:
	rm -rf $(OBJS)
	make -C mlx/ clean
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
