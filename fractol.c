#include "mlx/mlx.h"
#include "mlx/mlx_int.h"
#include <math.h>
#include <complex.h>
#include "fractol.h"

#define WIN_SX	1000	
#define WIN_SY	1000

void	put_square(void *img, int h, int w, int color);
void	put_circle(void *img, int h, int w, int color);
void	put_sq_triangle(void *img, int h, int w, int color);
void	put_triangle(void *img, int h, int w, int color);
void	plot_mandlebrot(void *img, int h, int w);
int		iter_eval(double complex c, int max_iter);
int		get_color(int i, int w);

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	*img;

	mlx = mlx_init();
	if (!mlx)
		exit(1);
	win = mlx_new_window(mlx, WIN_SX, WIN_SY, "Julia");
	if (!win)
		exit(1);
	mlx_key_hook(win, 
	img = data_init();
	if (!img)
		exit(1);
	img->img = mlx_new_image(mlx, WIN_SX, WIN_SY);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	plot_mandlebrot(img, WIN_SX, WIN_SY);
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
	mlx_loop(mlx);
}

#include <stdio.h>

void	plot_mandlebrot(void *img, int h, int w)
{
	double complex	c;
	double			x;
	double			y;
	int		max_iter;

	x = 1;
	max_iter = 100;
	while (x < w)
	{
		y = 1;
		while (y < h)
		{
			c = ((x - 500) / 250) + ((y - 500) / 250) * I;
			pixel_put(img, x, y, get_color(iter_eval(c, max_iter), w));
			y++;
		}
		x++;
	}
}

int	get_color(int i, int w)
{
	int color;
	i *= i * i;
	color = (i * 255) / w + (((i * 255) / w) << 8) + (((i * 255) / w) << 8);
	return (color);
}

int	iter_eval(double complex c, int max_iter)
{
	double complex	z;
	int				i;

	i = 0;
	z = 0;
	while (i < max_iter && cabs(z) < 2)
	{
		z = (z * z) + c;
		i++;
	}
	return (i);
}

void	put_triangle(void *img, int h, int w, int color)
{
	int	x;
	int	y;
	int	m;

	m = h / w;
	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			if (y == m * x || y == -m * x + h)
				pixel_put(img, y, x, color);
			y++;
		}
		x++;
	}
}

void	put_circle(void *img, int h, int w, int color)
{
	int	x;
	int y;

	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			if (sqrt(sq(w / 2 - x) + sq(h / 2 - y)) < w / 2)
				pixel_put(img, y, x, color);
			y++;
		}
		x++;
	}
}

void	put_sq_triangle(void *img, int h, int w, int color)
{
	int	x;
	int	y;
	int	m;

	m = h / w;
	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			if (y < m * x)
				pixel_put(img, y, x, color);
			y++;
		}
		x++;
	}
}

void	put_square(void *img, int h, int w, int color)
{
	int	x;
	int y;

	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			pixel_put(img, y, x, color);
			y++;
		}
		x++;
	}
}

