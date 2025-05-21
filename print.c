#include "fractol.h"

void	pixel_put(t_core *core, int x, int y, int color)
{
	char	*dst;

	dst = core->img_addr + (y * core->line_len + x * (core->bpp / 8));
	*(unsigned int *)dst = color;
}

void	plot_set(t_core *core)
{
	int	x;
	int	y;
	int	i;
	int	cutoff;

	cutoff = 0.9 * core->fractal->max_iter;
	x = 0;
	while (x < WIN_SX)
	{
		y = 0;
		while (y < WIN_SY)
		{
			i = calc_mandlebrot(x, y, core->fractal);
			if (i > cutoff)
				pixel_put(core, x, y, 0);
			else
				pixel_put(core, x, y, i * i * core->color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
}
