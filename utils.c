#include "fractol.h"

void	get_endian(t_core *core)
{
	int	a;

	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		core->endian = 1;
	else
		core->endian = 0;
}
