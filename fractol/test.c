#include "fractol.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	t_fractal *fractal;

	//printf("%d", is_mandelbrot((t_complex){atof(argv[1]), atof(argv[2])}));
	fractal_render(fractal);
}

