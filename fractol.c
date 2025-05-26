#include "fractol.h"

int	main(int ac, char **av)
{
	t_core	*core;

	core = malloc(sizeof(t_core));
	if (!core)
		exit(1);
	if (!param_check(ac, av))
		exit(0);
	init_core(core);
	core->fractal->type = param_check(ac, av);
	plot_set(core, get_set);
	disp_init_msg();
	mlx_loop_hook(core->mlx, psychadelic_hook, core);
	mlx_mouse_hook(core->win, mouse_hook, core);
	mlx_hook(core->win, MotionNotify, PointerMotionMask, julia_hook, core);
	mlx_key_hook(core->win, key_hook, core);
	mlx_hook(core->win, DestroyNotify, 0, &close_program, core);
	mlx_loop(core->mlx);
}
