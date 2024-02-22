/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:08:06 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/22 14:02:06 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_mandelbrot(t_complex c)
{
	t_complex	z;
	double temp_real;
	double temp_imag;
	int max_iter;
	double threshold;
	double magnitude;

	z.real = 0;
	z.imag = 0;
	threshold = 2.0;
	max_iter = 100;

	while (max_iter-- > 0)
	{
		//printf("%f, %f\n", z.real, z.imag);
		temp_real = (z.real * z.real) - (z.imag * z.imag) + c.real;
		temp_imag = 2 * z.real * z.imag + c.imag;

		z.real += temp_real;
		z.imag += temp_imag;
		magnitude = sqrt(z.real * z.real + z.imag * z.imag);
		//printf("Magnitude: %f\n", magnitude);
		if (magnitude > threshold)
			return (0);
	}
	return (1);
}
