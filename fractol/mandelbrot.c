/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:08:06 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/12 12:41:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, t_fractal *fractal)
{
	t_complex	z;
	double temp_imag;
	int i;
	double magnitude;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i < fractal->max_iter)
	{
		magnitude = z.real * z.real + z.imag * z.imag;
		if (magnitude > (fractal->threshold * fractal->threshold))	//not in mandelbrot set
			return (map(i, 0, fractal->max_iter, PSY_PURPLE, BLACK));
		temp_imag = 2 * z.real * z.imag + c.imag;
		z.real = (z.real * z.real) - (z.imag * z.imag) + c.real;
		z.imag = temp_imag;
		i++;
	}
	return (BLACK);	//in mandelbrot
}
