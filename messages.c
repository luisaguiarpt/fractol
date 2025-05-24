/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:59:16 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/24 02:49:50 by ldias-da         ###   ########.fr       */
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
	ft_printf("*      'S': Sinking ship                                  *\n");
	ft_printf("*                                                         *\n");
	ft_printf("*   Arrow keys to move around.                            *\n");
	ft_printf("*   '+' and '-' or mouse wheel to zoom in and out.        *\n");
	ft_printf("*   '[' and ']': Change max iteration                     *\n");
	ft_printf("*   'P': Psychadelic Mode (WARNING: Flashing lights!)     *\n");
	ft_printf("*   'I': Change the intensity of color change.            *\n");
	ft_printf("*   'C': Switch color range.                              *\n");
	ft_printf("*---------------------------------------------------------*\n");
	ft_printf("\n");
}

void	disp_options(void)
{
	ft_printf("\n");
	ft_printf(" No parameter passed.                       \n");
	ft_printf(" Usage: './fractol <set>'                   \n");
	ft_printf(" set: 'mandlebrot', 'julia', 'ship'         \n");
	ft_printf("\n");
}

void	wrong_options(void)
{
	ft_printf("\n");
	ft_printf(" Wrong parameter passed.                       \n");
	ft_printf(" Available sets: 'mandlebrot', 'julia', 'ship'         \n");
	ft_printf("\n");
}
