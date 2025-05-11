#include "fractol.h"

int	main(void)
{
	t_core	*core;

	core = malloc(sizeof(t_core));
	if (!core)
		exit(1);
	init_core(core);
	plot_set(core);
	mlx_loop_hook(core->mlx, psychadelic_hook, core);
	mlx_mouse_hook(core->win, mouse_hook, core);
	mlx_key_hook(core->win, key_hook, core);
	mlx_loop(core->mlx);
}
