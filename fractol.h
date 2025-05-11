#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "ft_printf/includes/ft_printf.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "keys.h"

# define WIN_SX	1000
# define WIN_SY	1000

typedef struct	s_fractal
{
	int		max_iter;
	double	zoom;
	double	x_offset;
	double	y_offset;
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
	int			psychadelic_mode;
}				t_core;

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

//	Calc functions - calc.c
int	calc_mandlebrot(int x, int y, t_fractal *f);

//	Struct functions - core.c
void		init_core(t_core *core);
t_fractal	*init_fractal(void);
void		close_program(t_core *core);

// Hook functions - hook.c
int	key_hook(int key, t_core *core);
int	mouse_hook(int button, int x, int y, t_core *core);
int	psychadelic_hook(t_core *core);

//	Put functions - print.c
void	pixel_put(t_core *core, int x, int y, int color);
void	plot_set(t_core *core);

// Aux functions - utils.c
void	get_endian(t_core *core);

#endif
