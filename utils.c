/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 00:01:25 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/29 18:21:19 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_set(int x, int y, t_core *core)
{
	if (core->fractal->type == 'm')
		return (calc_mandlebrot(x, y, core->fractal));
	else if (core->fractal->type == 'j')
		return (calc_julia(x, y, core->fractal));
	else if (core->fractal->type == 'n')
		return (calc_newton(x, y, core->fractal));
	return (1);
}

void	get_endian(t_core *core)
{
	int	a;

	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		core->endian = 1;
	else
		core->endian = 0;
}

void	reset_fractal(t_fractal *fractal)
{
	fractal->max_iter = 30;
	fractal->zoom = 300;
	if (fractal->type == 'm')
	{
		fractal->x_offset = WIN_SX / -fractal->zoom / 1.375;
		fractal->y_offset = WIN_SY / -fractal->zoom / 2;
	}
	else
	{
		fractal->x_offset = WIN_SX / -fractal->zoom / 2;
		fractal->y_offset = WIN_SY / -fractal->zoom / 2;
	}
	fractal->julia_cr = 0.0;
	fractal->julia_ci = 0.0;
}

void	change_color(t_core *core)
{
	static int	i;

	i++;
	i %= 8;
	if (i == 0)
		core->color = 0x000f00f0;
	else if (i == 1)
		core->color = 0x000000ff;
	else if (i == 2)
		core->color = 0x0000ff00;
	else if (i == 3)
		core->color = 0x00ff0000;
	else if (i == 4)
		core->color = 0x00ff00ff;
	else if (i == 5)
		core->color = 0x00ffff00;
	else if (i == 6)
		core->color = 0x000f0f0f;
	else if (i == 7)
		core->color = 0x00f0f0f0;
}
