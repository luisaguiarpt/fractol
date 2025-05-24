#include "fractol.h"

char	param_check(int ac, char **av)
{
	if (ac < 2)
	{
		disp_options();
		return (0);
	}
	if (!strcmp(av[1], "mandlebrot"))
		return ('m');
	else if (!strcmp(av[1], "julia"))
		return ('j');
	else if (!strcmp(av[1], "ship"))
		return ('s');
	else
	{
		wrong_options();
		return (0);
	}

}

int	get_set(int x, int y, t_core *core)
{
	if (core->fractal->type == 'm')
		return (calc_mandlebrot(x, y, core->fractal));
	else if (core->fractal->type == 'j')
		return (calc_julia(x, y, core->fractal));
//	else if (core->fractal->type == 's')
//		return (calc_ship(x, y, core->fractal));
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
