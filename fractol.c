/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 00:00:19 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/30 15:57:10 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_core	*core;

	if (!pre_check(ac, av))
		exit(1);
	core = malloc(sizeof(t_core));
	if (!core)
		exit(1);
	init_core(core);
	if (!param_check(ac, av, core->fractal))
		exit(0);
	plot_set(core, get_set);
	disp_init_msg();
	mlx_loop_hook(core->mlx, psychadelic_hook, core);
	mlx_mouse_hook(core->win, mouse_hook, core);
	mlx_hook(core->win, MotionNotify, PointerMotionMask, mouse_move_hook, core);
	mlx_key_hook(core->win, key_hook, core);
	mlx_hook(core->win, DestroyNotify, 0, &close_program, core);
	mlx_loop(core->mlx);
}
