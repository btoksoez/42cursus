/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:53:24 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/23 16:26:11 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double value, double old_min, double old_max, double new_min, double new_max)
{
	value = (value - old_min) * (new_max - new_min) / (old_max - old_min) + new_min;
	return (value);
}

void my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	double new_x;
	double new_y;
	unsigned int *img_pixel;
	t_complex c;
	int	color;

	img_pixel = (unsigned int *)fractal->img.pixels_ptr;
	new_x = map(x, 0, WIDTH, -fractal->zoomx, fractal->zoomx);
	new_y = map(y, 0, HEIGHT, fractal->zoomy, -fractal->zoomy);
	c.real = new_x;
	c.imag = new_y;
	color = map(is_mandelbrot(c, fractal), BLACK, WHITE, 0, fractal->max_iter);
	my_pixel_put(x, y, &fractal->img, color);
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

// void	fractal_render_zoom(t_fractal *fractal, int x, int y)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < HEIGHT)
// 	{
// 		x = -1;
// 		while (++x < WIDTH)
// 		{
// 			handle_pixel(x, y, fractal);
// 		}
// 	}
// 	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img_ptr, 0, 0);
// }
