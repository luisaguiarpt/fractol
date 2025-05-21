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
		core->fractal->y_offset -= 100 / core->fractal->zoom;
	else if (key == DOWN)
		core->fractal->y_offset += 100 / core->fractal->zoom;
	else if (key == LEFT)
		core->fractal->x_offset -= 100 / core->fractal->zoom;
	else if (key == RIGHT)
		core->fractal->x_offset += 100 / core->fractal->zoom;
	else if (key == P)
		core->psy_mode = (core->psy_mode == 0) * 1 + (core->psy_mode == 1) * 0;
	else if (key == L_BRA || key == R_BRA)
		key_hook_iter(key, core);
	else if (key == PLUS || key == MINUS)
		key_hook_zoom(key, core);
	plot_set(core);
	return (0);
}

int	key_hook_zoom(int key, t_core *core)
{
	t_complex	c;
	int			x;
	int			y;

	x = WIN_SX / 2;
	y = WIN_SY / 2;
	c.r = (x / core->fractal->zoom) + core->fractal->x_offset;
	c.i = (y / core->fractal->zoom) + core->fractal->y_offset;
	if (key == PLUS)
	{
		core->fractal->zoom *= 1.25;
		core->fractal->x_offset = c.r - (x / core->fractal->zoom);
		core->fractal->y_offset = c.i - (y / core->fractal->zoom);
	}
	else if (key == MINUS)
	{
		core->fractal->zoom /= 1.25;
		core->fractal->x_offset = c.r - (x / core->fractal->zoom);
		core->fractal->y_offset = c.i - (y / core->fractal->zoom);
	}
	return (0);
}

int	key_hook_iter(int key, t_core *core)
{
	if (key == L_BRA)
	{
		if (core->fractal->max_iter > 100)
			core->fractal->max_iter -= 100;
		ft_printf("Iterations: %d\n", core->fractal->max_iter);
	}
	else if (key == R_BRA)
	{
		if (core->fractal->max_iter <= 1000)
			core->fractal->max_iter += 100;
		ft_printf("Iterations: %d\n", core->fractal->max_iter);
	}
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
		core->fractal->zoom *= 1.25;
		core->fractal->x_offset = c.r - (x / core->fractal->zoom);
		core->fractal->y_offset = c.i - (y / core->fractal->zoom);
	}
	else if (button == SCR_DOWN)
	{
		core->fractal->zoom /= 1.25;
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

	if (!core->psy_mode)
		return (0);
	i = 0;
	while (i < WIN_SX * WIN_SY)
	{
		dst = core->img_addr + i * (core->bpp / 8);
		if (*(unsigned int *)dst > 100)
			*(unsigned int *)dst += core->fractal->intense;
		else
			dst += 0;
		i++;
	}
	mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
	return 0;
}
