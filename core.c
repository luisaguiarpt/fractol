/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:54:41 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/28 21:55:09 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_core(t_core *core)
{
	core->mlx = mlx_init();
	if (!core->mlx)
		exit(1);
	core->win = mlx_new_window(core->mlx, WIN_SX, WIN_SY, "fract-ol");
	if (!core->win)
		exit(1);
	core->img = mlx_new_image(core->mlx, WIN_SX, WIN_SY);
	if (!core->img)
		exit(1);
	get_endian(core);
	core->img_addr = mlx_get_data_addr(core->img, &core->bpp, &core->line_len, &core->endian);
	core->fractal = init_fractal();
	core->color = 0x00f00f0;
	core->psy_mode = 0;
	core->fractal->intense = 169;
}

t_fractal	*init_fractal(void)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		exit(1);
	reset_fractal(fractal);
	fractal->type = 0;
	fractal->follow_mouse = 0;
	fractal->n = init_newton();
	return (fractal);
}

t_newton	*init_newton(void)
{
	t_newton	*n;

	n = malloc(sizeof(t_newton));
	if (!n)
		exit(1);
	return (n);
}

int	close_program(t_core *core)
{
	mlx_destroy_image(core->mlx, core->img);
	mlx_destroy_window(core->mlx, core->win);
	mlx_destroy_display(core->mlx);
	free(core->fractal->n);
	free(core->fractal);
	free(core->mlx);
	free(core);
	exit (0);
}
