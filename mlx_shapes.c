#include "mlx/mlx.h"
#include "mlx/mlx_int.h"
#include "fractol.h"

void	put_square(void *img, int h, int w, int color);
void	put_circle(void *img, int h, int w, int color);
void	put_sq_triangle(void *img, int h, int w, int color);
void	put_triangle(void *img, int h, int w, int color);

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

