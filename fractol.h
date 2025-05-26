#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "ft_printf/includes/ft_printf.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "keys.h"

# define WIN_SX	1920
# define WIN_SY 1080

typedef struct	s_fractal
{
	int		max_iter;
	double	zoom;
	double	x_offset;
	double	y_offset;
	int		intense;
	char	type;
	double	julia_cr;
	double	julia_ci;
}				t_fractal;

typedef	struct	s_core
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

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

//	Calc functions - calc.c
int	calc_mandlebrot(int x, int y, t_fractal *f);
int	calc_julia(int x, int y, t_fractal *f);

//	Struct functions - core.c
void		init_core(t_core *core);
t_fractal	*init_fractal(void);
int			close_program(t_core *core);

// Hook functions - hook.c
int	key_hook(int key, t_core *core);
int	key_hook_iter(int key, t_core *core);
int	key_hook_zoom(int key, t_core *core);
int	key_hook_options(int key, t_core *core);
int	key_hook_color(int key, t_core *core);
int	mouse_hook(int button, int x, int y, t_core *core);
int	mouse_move_hook(int x, int y, t_core *core);
int	psychadelic_hook(t_core *core);
int	julia_hook(int x, int y, t_core *core);

//	Put functions - print.c
void	pixel_put(t_core *core, int x, int y, int color);
void	plot_set(t_core *core, int (*set)(int, int, t_core *));

// Message functions - messages.c
void	disp_init_msg(void);
void	disp_options(void);
void	wrong_options(void);

// Aux functions - utils.c
void	get_endian(t_core *core);
int		get_set(int x, int y, t_core *core);
char	param_check(int ac, char **av);
void	change_color(t_core *core);

#endif
