#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <stdlib.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

}				t_data;

//	Struct functions
t_data	*data_init(void);
//	Put functions
void	pixel_put(t_data *data, int x, int y, int color);
//	Math functions
int	sq(int x);

#endif
