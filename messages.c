/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:59:16 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/28 21:26:56 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	disp_init_msg(void)
{
	ft_printf("\n");
	ft_printf("*---------------------------------------------------------*\n");
	ft_printf("* Use the following keys:                                 *\n");
	ft_printf("*   Switch sets:                                          *\n");
	ft_printf("*      'M': Mandlebrot                                    *\n");
	ft_printf("*      'J': Julia                                         *\n");
	ft_printf("*      'N': Newton                                        *\n");
	ft_printf("*                                                         *\n");
	ft_printf("*   'ESC' to close the program.                           *\n");
	ft_printf("*   'R' to reset the fractal to original state.           *\n");
	ft_printf("*   Arrow keys to move around.                            *\n");
	ft_printf("*   '+' and '-' or mouse wheel to zoom in and out.        *\n");
	ft_printf("*   '[' and ']': Change max iteration                     *\n");
	ft_printf("*   'F': Makes the julia fractal change with mouse pos.   *\n");
	ft_printf("*   'P': Psychadelic Mode (WARNING: Flashing lights!)     *\n");
	ft_printf("*   'I': Change the intensity of color change.            *\n");
	ft_printf("*   'C': Switch color range.                              *\n");
	ft_printf("*---------------------------------------------------------*\n");
	ft_printf("\n");
}

int	disp_options(void)
{
	ft_printf("\n");
	ft_printf("No parameter passed.                       \n");
	ft_printf("Usage: './fractol <set> <option>'          \n");
	ft_printf("set: 'mandlebrot', 'julia', 'newton'       \n");
	ft_printf("option (only for julia):                   \n");
	ft_printf("	   1 - 5 for different julia fractals     \n");
	ft_printf("\n");
	return (0);
}

int	wrong_options(void)
{
	ft_printf("\n");
	ft_printf(" Wrong parameter(s) passed.                         \n");
	ft_printf(" Available sets: 'mandlebrot', 'julia', 'newton'    \n");
	ft_printf(" Option only possible for julia (1 - 5) .           \n");
	ft_printf("\n");
	return (0);
}
