/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 00:02:34 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/29 00:11:22 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "libft/libft/libft.h"
# include "libft/ft_printf/includes/ft_printf.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "keys.h"

# define WIN_SX	720
# define WIN_SY 640

typedef struct s_newton
{
	double	bailout_calc;
	double	zi_prev;
	double	r2;
	double	i2;
	double	r3;
	double	i3;
}				t_newton;

typedef struct s_fractal
{
	int			max_iter;
	double		zoom;
	double		x_offset;
	double		y_offset;
	int			intense;
	char		type;
	double		julia_cr;
	double		julia_ci;
	t_newton	*n;
	int			follow_mouse;
}				t_fractal;

typedef struct s_core
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_fractal	*fractal;
	int			color;
	int			psy_mode;
}				t_core;

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

//	Calc functions - calc.c
int			calc_mandlebrot(int x, int y, t_fractal *f);
int			calc_julia(int x, int y, t_fractal *f);
int			calc_newton(int x, int y, t_fractal *f);
void		newton_aux(t_complex *z, t_newton *n);
int			check_conv(t_complex z);

//	Struct functions - core.c
t_fractal	*init_fractal(void);
t_newton	*init_newton(void);
void		init_core(t_core *core);
int			close_program(t_core *core);

// Hook functions - hook.c hook_utils.c
int			key_hook(int key, t_core *core);
int			key_hook_iter(int key, t_core *core);
int			key_hook_zoom(int key, t_core *core);
int			key_hook_options(int key, t_core *core);
int			key_hook_color(int key, t_core *core);
int			mouse_hook(int button, int x, int y, t_core *core);
int			mouse_move_hook(int x, int y, t_core *core);
int			psychadelic_hook(t_core *core);
int			julia_hook(int x, int y, t_core *core);

//	Put functions - print.c
void		pixel_put(t_core *core, int x, int y, int color);
void		plot_set(t_core *core, int (*set)(int, int, t_core *));

// Message functions - messages.c
void		disp_init_msg(void);
int			disp_options(void);
int			wrong_options(void);

// Check functions - checks.c
int			pre_check(int ac, char **av);
char		param_check(int ac, char **av, t_fractal *f);
int			check_julia(int opt, t_fractal *f);

// Aux functions - utils.c
void		get_endian(t_core *core);
int			get_set(int x, int y, t_core *core);
void		change_color(t_core *core);
void		reset_fractal(t_fractal *fractal);

#endif
