/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 23:59:25 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/28 23:59:28 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	param_check(int ac, char **av, t_fractal *f)
{
	if (ac < 2)
		return (disp_options());
	if (!strcmp(av[1], "mandlebrot") && ac == 2)
		f->type = 'm';
	else if (!strcmp(av[1], "newton") && ac == 2)
		f->type = 'n';
	else if (!strcmp(av[1], "julia") && ac <= 3)
	{
		if (av[2] && !check_julia(ft_atoi(av[2]), f))
			return (wrong_options());
		f->type = 'j';
	}
	reset_fractal(f);
	if (f->type == 0)
		return (wrong_options());
	else
		return (1);
}

int	pre_check(int ac, char **av)
{
	if (ac < 2)
		return (disp_options());
	if (!strcmp(av[1], "mandlebrot") && ac == 2)
		return (1);
	else if (!strcmp(av[1], "newton") && ac == 2)
		return (1);
	else if (!strcmp(av[1], "julia") && ac <= 3)
	{
		if (av[2] && (ft_atoi(av[2]) < 1 || ft_atoi(av[2]) > 5))
			return (wrong_options());
		return (1);
	}
	else
		return (0);
}

int	check_julia(int opt, t_fractal *f)
{
	if (opt == 1)
		f->julia_cr = -0.998788;
	if (opt == 1)
		f->julia_ci = -0.260000;
	if (opt == 2)
		f->julia_cr = -0.218788;
	if (opt == 2)
		f->julia_ci = -0.773333;
	if (opt == 3)
		f->julia_cr = 0.351212;
	if (opt == 3)
		f->julia_ci = 0.436667;
	if (opt == 4)
		f->julia_cr = 0.391212;
	if (opt == 4)
		f->julia_ci = 0.166667;
	if (opt == 5)
		f->julia_cr = -1.400000;
	if (opt == 5)
		f->julia_ci = 0.000000;
	if (opt >= 1 && opt <= 5)
		return (1);
	else
		return (0);
}
