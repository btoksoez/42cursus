/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:53:24 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 12:20:41 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double value, double old_max, double new_min, double new_max)
{
	return (value * (new_max - new_min) / old_max + new_min);
}

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

int	calculate_fractal(t_complex c, t_fractal *f)
{
	if (f->name == MANDELBROT)
		return (mandelbrot(c, f));
	else if (f->name == JULIA)
		return (julia(c, f));
	else if (f->name == MANDELBOX)
		return (mandelbox(c, f));
	else
		return (help_message(0));
}

void	fractal_render(t_fractal *f)
{
	int			x;
	int			y;
	t_complex	c;
	int			color;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c.real = f->min_r + x * (f->max_r - f->min_r) / WIDTH;
			c.imag = f->max_i + y * (f->min_i - f->max_i) / HEIGHT;
			color = calculate_fractal(c, f);
			my_pixel_put(x, y, &f->img, color);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
}
