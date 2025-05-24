CC=cc
FLAGS=-Wall -Wextra -Werror -g
INCM=mlx
INCP=ft_printf
LIBS=-lmlx -lXext -lX11 -lm

SRCS=calc.c core.c utils.c fractol.c hooks.c hooks_utils.c messages.c print.c

OBJS=$(SRCS:%.c=%.o)

MLX=mlx/libmlx.a
PRINTF=ft_printf/libftprintf.a
NAME=fractol

all: $(NAME)

$(NAME): $(OBJS) makelibs
	$(CC) $(FLAGS) $(OBJS) $(MLX) $(PRINTF) -o $@ -I$(INCS) $(LIBS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INCM) -I$(INCP)

makelibs:
	make -C mlx/ all
	make -C ft_printf/ all

clean:
	rm -rf $(OBJS)
	make -C mlx/ clean
	make -C ft_printf/ clean

fclean: clean
	rm -rf $(NAME)

re: fclean all
