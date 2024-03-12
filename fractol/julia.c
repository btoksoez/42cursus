/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:10:48 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/12 12:46:57 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex z, t_fractal *f)
{
	int	i;
	double magnitude;
	double	temp_imag;

	i = 0;
	while (i < f->max_iter)
	{
		magnitude = z.real * z.real + z.imag * z.imag;
		if (magnitude > (f->threshold * f->threshold))	//not in julia set
			return (map(i, 0, f->max_iter, PSY_PURPLE, BLACK));
		temp_imag = 2 * z.real * z.imag + f->julia_c.imag;
		z.real = (z.real * z.real) - (z.imag * z.imag) + f->julia_c.real;
		z.imag = temp_imag;
		i++;
	}
	return (BLACK);	//in julia
}
