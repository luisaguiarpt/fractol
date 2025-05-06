#include "fractol.h"

t_data	*data_init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	return (data);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

//void	get_endian(t_sysdef *sysdef)
//{
//	int	a;
//
//	a = 0x11223344;
//	if (((unsigned char *)&a)[0] == 0x11)
//		sysdef->local_endian = 1;
//	else
//		sysdef->local_endian = 0;
//}
