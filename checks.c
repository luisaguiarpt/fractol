/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 23:59:25 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/30 11:52:02 by ldias-da         ###   ########.fr       */
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
	else if (!strcmp(av[1], "julia") && ac <= 4)
	{
		f->type = 'j';
		if (ac == 2)
			return (1);
		if (ac == 3)
			return (wrong_options());
		if (!ft_isdouble(av[2]) || !ft_isdouble(av[3]))
			return (wrong_options());
		f->julia_cr = ft_atod(av[2]);
		f->julia_ci = ft_atod(av[3]);
	}
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
	else if (!strcmp(av[1], "julia") && ac <= 4)
	{
		if (ac == 2)
			return (1);
		if (ac == 3)
			return (wrong_options());
		if (!ft_isdouble(av[2]) || !ft_isdouble(av[3]))
			return (wrong_options());
		return (1);
	}
	else
		return (wrong_options());
}
