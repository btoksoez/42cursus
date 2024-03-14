/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:08:06 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/13 13:10:54 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, t_fractal *fractal)
{
	t_complex	z;
	double		temp_imag;
	int			i;
	double		magnitude;
	int			color;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i < fractal->max_iter)
	{
		magnitude = z.real * z.real + z.imag * z.imag;
		if (magnitude > (fractal->threshold * fractal->threshold))
		{
			if (fractal->fast == 1)
				return (map(i, fractal->max_iter, GRAD_START, GRAD_END));
			color = map(i, fractal->max_iter, 0, 256);
			return (fractal->palette[color]);
		}
		temp_imag = 2 * z.real * z.imag + c.imag;
		z.real = (z.real * z.real) - (z.imag * z.imag) + c.real;
		z.imag = temp_imag;
		i++;
	}
	return (GRAD_START);
}
