#include "fractol.h"
#include <stdlib.h>

double	map(double value, double old_min, double old_max, double new_min, double new_max)
{
	value = (value - old_min) * (new_max - new_min) / (old_max - old_min) + new_min;
	return (value);
}

int main(int argc, char *argv[])
{
	t_fractal *fractal;
	int i = 0;
	int color;
	//printf("%d", is_mandelbrot((t_complex){atof(argv[1]), atof(argv[2])}));
	while (i++ < 100)
	{
		color = map(i, BLACK, WHITE, 0, 100);
		printf("Old: %d, New: %d\n", i , color);
	}
}

