/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:49:18 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/13 13:10:54 by btoksoez         ###   ########.fr       */
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

int mandelbox(t_complex c, t_fractal *fractal)
{
	double s;
	double	r;
	double	f;
	t_complex v;
	int i;
	double magnitude;

	i = 0;
	s = 2.0;
	r = 0.5;
	f = 1.0;
	v.real = c.real;
	v.imag = c.imag;
	while (i < fractal->max_iter)
	{
		printf("%d\n", i);
		v.real = f * box_fold(v.real);
		v.imag = f * box_fold(v.imag);
		magnitude = sqrt(v.real * v.real + v.imag * v.imag);
		v.real = v.real * s * ball_fold(r, magnitude) + c.real;
		v.imag = v.imag * s * ball_fold(r, magnitude) + c.imag;
		if (magnitude > fractal->threshold)	//not in mandelbox set
		{
			if (fractal->fast == 1)
				return (map(i, fractal->max_iter, GRAD_START, GRAD_END));
			int color = map(i, fractal->max_iter, 0, 256);
			return (PSY_PINK);
		}
		i++;
	}
	return (GRAD_START);	//in mandelbox
}
