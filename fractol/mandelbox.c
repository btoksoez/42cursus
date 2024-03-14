/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:49:18 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 12:12:54 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	box_fold(double v)
{
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

int	mandelbox(t_complex c, t_fractal *f)
{
	t_complex	v;
	int			i;
	double		magnitude;

	i = 0;
	v.real = c.real;
	v.imag = c.imag;
	while (i < f->max_iter)
	{
		v.real = f->box_f * box_fold(v.real);
		v.imag = f->box_f * box_fold(v.imag);
		magnitude = sqrt(v.real * v.real + v.imag * v.imag);
		v.real = v.real * f->box_s * ball_fold(f->box_r, magnitude) + c.real;
		v.imag = v.imag * f->box_s * ball_fold(f->box_r, magnitude) + c.imag;
		if (magnitude > f->threshold && f->fast == 1)
			return (map(i, f->max_iter, GRAD_START, GRAD_END));
		if (magnitude > f->threshold)
			return (f->palette[(int)map(i, f->max_iter, 0, 256)]);
		i++;
	}
	return (GRAD_START);
}
