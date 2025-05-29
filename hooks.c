/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 00:00:31 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/29 00:00:50 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if (key == P || key == J || key == M || key == N || key == I)
		key_hook_options(key, core);
	else if (key == L_BRA || key == R_BRA)
		key_hook_iter(key, core);
	else if (key == PLUS || key == MINUS)
		key_hook_zoom(key, core);
	else if (key == C || key == R || key == F)
		key_hook_color(key, core);
	plot_set(core, get_set);
	return (0);
}

int	key_hook_color(int key, t_core *core)
{
	if (key == C)
		change_color(core);
	else if (key == R)
		reset_fractal(core->fractal);
	else if (key == F && core->fractal->follow_mouse == 0)
		core->fractal->follow_mouse = 1;
	else if (key == F && core->fractal->follow_mouse == 1)
		core->fractal->follow_mouse = 0;
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
	plot_set(core, get_set);
	return (0);
}

int	mouse_move_hook(int x, int y, t_core *core)
{
	if (core->fractal->type == 'j' && core->fractal->follow_mouse)
		julia_hook(x, y, core);
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
	return (0);
}
