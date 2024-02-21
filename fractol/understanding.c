#include "libft/libft.h"
#include <stdio.h>

typedef struct s_complex
{
	double	real;
	double	i;
}			t_complex;

t_complex f(t_complex z, t_complex c)
{
	t_complex res;
	double temp_real;

	res.real = 0;
	res.i = 0;

	temp_real = (z.real * z.real) - (z.i * z.i);
	res.i = 2 * z.real * z.i;
	res.real = temp_real;
	res.real += c.real;
	res.i += c.real;
	return (res);
}

int main(void)
{
	t_complex	z;
	t_complex	c;
	double temp_real;

	z.real = 0;
	z.i = 0;

	c.real = 0.25;
	c.i = 0.4;

	for (int i = 0; i < 42; ++i)
	{
		temp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = temp_real;

		z.real += c.real;
		z.i += c.i;
		printf("Iteration %d: real: %f imaginary %f\n", i, z.real, z.i);
	}
}


