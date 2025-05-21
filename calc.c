#include "fractol.h"

int	calc_mandlebrot(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	double		zr_temp;
	int			i;

	c.r = (x / f->zoom) + f->x_offset;
	c.i = (y / f->zoom) + f->y_offset;
	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	while ((z.r * z.r + z.i * z.i) < 4 && i <= f->max_iter)
	{
		zr_temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = zr_temp;
		i++;
	}
	return (i);
}
