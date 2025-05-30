/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 23:58:33 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/30 11:48:12 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	calc_julia(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	double		zr_temp;
	int			i;

	z.r = (x / f->zoom) + f->x_offset;
	z.i = (y / f->zoom) + f->y_offset;
	i = 0;
	c.r = f->julia_cr;
	c.i = f->julia_ci;
	while ((z.r * z.r + z.i * z.i) < 4 && i <= f->max_iter)
	{
		zr_temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = zr_temp;
		i++;
	}
	return (i);
}

int	calc_newton(int x, int y, t_fractal *f)
{
	t_complex	z;
	int			i;
	double		bail_lim;

	z.r = (x / f->zoom) + f->x_offset;
	z.i = (y / f->zoom) + f->y_offset;
	i = 0;
	f->n->bail_calc = 0;
	f->n->zi_prev = z.i;
	bail_lim = 1000000000000.0 * f->zoom;
	while (f->n->bail_calc < bail_lim && i <= f->max_iter && check_conv(z, f))
	{
		newton_aux(&z, f->n);
		f->n->zi_prev = z.i;
		i++;
	}
	return (i);
}

// Calculates convergence to the roots of the newton equation
int	check_conv(t_complex z, t_fractal *f)
{
	double		tol;
	t_complex	rt2;
	t_complex	rt3;

	tol = 0.0000000001 / f->zoom;
	rt2.r = -0.5;
	rt2.i = 0.8660254037844386;
	rt3.r = -0.5;
	rt3.i = -0.8660254037844386;
	if ((z.r - 1) * (z.r - 1) + z.i * z.i < tol)
		return (0);
	if ((z.r - rt2.r) * (z.r - rt2.r) + (z.i - rt2.i) * (z.i - rt2.i) < tol)
		return (0);
	if ((z.r - rt3.r) * (z.r - rt3.r) + (z.i - rt3.i) * (z.i - rt3.i) < tol)
		return (0);
	return (1);
}

// Calculates the real and imag parts in the newton equation
// as well as the bailout
void	newton_aux(t_complex *z, t_newton *n)
{
	double	zr_nom;
	double	zi_nom;
	double	denom;

	n->r2 = z->r * z->r;
	n->i2 = z->i * z->i;
	n->r3 = z->r * z->r * z->r;
	n->i3 = z->i * z->i * z->i;
	zr_nom = 3 * (n->r3 - 3 * z->r * n->i2 - 1) * (n->r2 - n->i2)
		+ 6 * z->r * z->i * (3 * n->r2 * z->i - n->i3);
	zi_nom = 3 * (3 * n->r2 * z->i - n->i3) * (n->r2 - n->i2)
		- 6 * z->r * z->i * (n->r3 - 3 * z->r * n->i2 - 1);
	denom = 9 * (n->r2 - n->i2) * (n->r2 - n->i2) + 36 * n->r2 * n->i2;
	z->r = z->r - zr_nom / denom;
	z->i = z->i - zi_nom / denom;
	n->bail_calc = z->r * z->r + z->i * z->i;
}
