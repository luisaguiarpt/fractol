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
	core->color = 0x000f000;
	core->psychadelic_mode = 0;
}

t_fractal	*init_fractal(void)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		exit(1);
	fractal->max_iter = 100;
	fractal->zoom = 300;
	fractal->x_offset = -2.1;
	fractal->y_offset = -1.7;
	return (fractal);
}

void	close_program(t_core *core)
{
	mlx_destroy_image(core->mlx, core->img);
	mlx_destroy_window(core->mlx, core->win);
	mlx_destroy_display(core->mlx);
	free(core->fractal);
	free(core);
	exit(0);
}
