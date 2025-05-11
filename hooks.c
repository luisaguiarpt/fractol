#include "fractol.h"

int	key_hook(int key, t_core *core)
{
	ft_printf("Pressed key: %d\n", key);
	if (key == ESC)
	{
		close_program(core);
		exit(0);
	}
	else if (key == UP)
		core->fractal->y_offset -= 0.42;
	else if (key == DOWN)
		core->fractal->y_offset += 0.42;
	else if (key == LEFT)
		core->fractal->x_offset -= 0.42;
	else if (key == RIGHT)
		core->fractal->x_offset += 0.42;
	else if (key == P)
	{
		if (core->psychadelic_mode == 1)
			core->psychadelic_mode = 0;
		else if (core->psychadelic_mode == 0)
			core->psychadelic_mode = 1;
	}
	plot_set(core);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_core *core)
{
	t_complex	c;

	c.r = (x / core->fractal->zoom) + core->fractal->x_offset;
	c.i = (y / core->fractal->zoom) + core->fractal->y_offset;
	ft_printf("Mouse at %dx%d.\n", x, y);
	if (button == SCR_UP)
	{
		core->fractal->zoom *= 1.1;
		core->fractal->x_offset = c.r - (x / core->fractal->zoom);
		core->fractal->y_offset = c.i - (y / core->fractal->zoom);
	}
	else if (button == SCR_DOWN)
	{
		core->fractal->zoom /= 1.1;
		core->fractal->x_offset = c.r - (x / core->fractal->zoom);
		core->fractal->y_offset = c.i - (y / core->fractal->zoom);
	}
	plot_set(core);
	return (0);
}

int	psychadelic_hook(t_core *core)
{
	int				i;
	char			*dst;
	static double	t;
	int				rgb[3];
	int				color;

	if (!core->psychadelic_mode)
		return (0);
	t = 0;
	i = 0;
	while (i < WIN_SX * WIN_SY)
	{
		rgb[0] = (int)((sin(t + i * 0.8) * 0.00123 + 0.0013) * 255);
		rgb[1] = (int)((sin(t + i * 1.6) * -0.00456 + 0.025) * 255);
		rgb[2] = (int)((sin(t + i * 2.4) * 0.001823 + 0.0371) * 255);
		color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
		dst = core->img_addr + i * (core->bpp / 8);
		*(unsigned int *)dst += color;
		i++;
	}	
	mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
	t += 0.01;
	return 0;
}
