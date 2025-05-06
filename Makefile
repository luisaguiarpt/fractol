CC=cc
FLAGS=-Wall -Wextra -Werror -g
INCS=mlx
LIBS=-lmlx -lXext -lX11 -lm

SRCS=fractol.c data_utils.c my_math.c

OBJS=$(SRCS:%.c=%.o)

MLX=mlx/libmlx.a
NAME=fractol

all: $(NAME)

$(NAME): $(OBJS) makemlx
	$(CC) $(FLAGS) $(OBJS) $(MLX) -o $@ -I$(INCS) $(LIBS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INCS)

makemlx:
	make -C mlx/ all

clean:
	rm -rf $(OBJS)
	make -C mlx/ clean

fclean: clean
	rm -rf $(NAME)

re: fclean all
