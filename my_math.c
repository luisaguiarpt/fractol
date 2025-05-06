#include <limits.h>
#include "fractol.h"

int	sq(int x)
{
	if (x > 0 && x > INT_MAX / x)
		return (-1);
	return (x * x);	
}
