#include "fractol.h"

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
			core->fractal->max_iter -= 50;
		ft_printf("Iterations: %d\n", core->fractal->max_iter);
	}
	else if (key == R_BRA)
	{
		if (core->fractal->max_iter <= 1000)
			core->fractal->max_iter += 50;
		ft_printf("Iterations: %d\n", core->fractal->max_iter);
	}
	return (0);
}

int	key_hook_options(int key, t_core *core)
{
	if (key == P)
		core->psy_mode = (core->psy_mode == 0) * 1 + (core->psy_mode == 1) * 0;
	else if (key == J)
		core->fractal->type = 'j';
	else if (key == M)
		core->fractal->type = 'm';
	else if (key == S)
		core->fractal->type = 's';
	else if (key == I)
	{
		core->fractal->intense += 100;
		core->fractal->intense %= 1000;
		ft_printf("Intensity: %d\n", core->fractal->intense);
	}
	else
		return (1);
	return (0);
}

int	julia_hook(int x, int y, t_core *core)
{
	static int	i;
	core->fractal->julia_cr = (x / core->fractal->zoom) + core->fractal->x_offset;
	core->fractal->julia_ci = (y / core->fractal->zoom) + core->fractal->y_offset;
	ft_printf("Mouse at x=%d, y=%d.\n", x, y);
	i++;
	if (i % 10 == 0)
		plot_set(core, get_set);
	return (0);
}
