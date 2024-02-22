/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:53:24 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/22 14:01:17 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double value, double old_min, double old_max, double new_min, double new_max)
{
	value = (value - old_min) * (new_max - new_min) / (old_max - old_min) + new_min;
	return (value);
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	double new_x;
	double new_y;
	unsigned int *img_pixel;
	t_complex c;

	img_pixel = (unsigned int *)fractal->img.pixels_ptr;
	new_x = map(x, 0, WIDTH, -2, 2);
	new_y = map(y, 0, HEIGHT, -1, 2);
	c.real = new_x;
	c.imag = new_y;
	if (is_mandelbrot(c))
		img_pixel[y * WIDTH + x] = 0xff;
	else
		img_pixel[y * WIDTH + x] = 0xff00;
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img_ptr, 0, 0);
}
