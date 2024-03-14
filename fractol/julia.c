/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:10:48 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/13 13:14:14 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex z, t_fractal *f)
{
	int		i;
	double	magnitude;
	double	temp_imag;
	int		color;

	i = 0;
	while (i < f->max_iter)
	{
		magnitude = z.real * z.real + z.imag * z.imag;
		if (magnitude > (f->threshold * f->threshold))
		{
			if (f->fast == 1)
				return (map(i, f->max_iter, GRAD_START, GRAD_END));
			color = map(i, f->max_iter, 0, 256);
			return (f->palette[color]);
		}
		temp_imag = 2 * z.real * z.imag + f->julia_c.imag;
		z.real = (z.real * z.real) - (z.imag * z.imag) + f->julia_c.real;
		z.imag = temp_imag;
		i++;
	}
	return (GRAD_START);
}
