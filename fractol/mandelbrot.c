/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:08:06 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/23 18:29:34 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_mandelbrot(t_complex c, t_fractal *fractal)
{
	t_complex	z;
	double temp_real;
	double temp_imag;
	int i;
	double magnitude;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i < fractal->max_iter)
	{
		//printf("%f, %f\n", z.real, z.imag);
		temp_real = (z.real * z.real) - (z.imag * z.imag) + c.real;
		temp_imag = 2 * z.real * z.imag + c.imag;

		z.real += temp_real;
		z.imag += temp_imag;
		magnitude = z.real * z.real + z.imag * z.imag;
		if (magnitude > (fractal->threshold * fractal->threshold))	//not in mandelbrot set
			return (map(i, 0, fractal->max_iter, WHITE, BLACK));
		i++;
	}
	return (PSY_MAGENTA);	//in mandelbrot
}