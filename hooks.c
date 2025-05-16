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

#define BASE_FREQUENCY	10
#define NUM_HARMONICS	3

int	clamp(int value, int min, int max)
{
	if (value < min)
		return min;
	if (value > max)
		return max;
	return (value);
}

void	apply_fourier(char *dst, float time)
{
	float	phase;
	float	rgb[3];
	int		i;
	int		k;
	int		size;
	int		colors[3];

	i = -1;
	k = 0;
	size = WIN_SX * WIN_SY;
	while (++i < size * 4)
	{
		phase = time + i * BASE_FREQUENCY;
		rgb[0] = 0;
		while (++k <= NUM_HARMONICS)
		{
			rgb[0] += (1.0 / k) * sin(k * phase);
			rgb[1] += (1.0 / k) * sin(k * phase + M_PI / 3);
			rgb[2] += (1.0 / k) * sin(k * phase + 2 * M_PI / 3);
		}
		colors[0] = clamp((int)(127.5 * (1 + rgb[0])), 0, 255);
		colors[1] = clamp((int)(127.5 * (1 + rgb[1])), 0, 255);
		colors[2] = clamp((int)(127.5 * (1 + rgb[2])), 0, 255);
		dst[i] += (colors[0] << 16) | (colors[1] << 8) | colors[2];
	}
}

int	psychadelic_hook(t_core *core)
{
//	int				i;
//	char			*dst;
	static float	t;
	//unsigned char	rgb[3];

	if (!core->psychadelic_mode)
		return (0);
	t = 0;
	apply_fourier(core->img_addr, t);
	//dst = core->img_addr + i * (core->bpp / 8);
	//*(unsigned int *)dst += color;
	
	mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
	t += 0.1;
	return 0;
}

