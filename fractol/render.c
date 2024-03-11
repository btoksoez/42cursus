/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:53:24 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/11 13:43:10 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double value, double old_min, double old_max, double new_min, double new_max)
{
	return (value - old_min) * (new_max - new_min) / (old_max - old_min) + new_min;
}

void my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

int	calculate_fractal(t_complex c, t_fractal *f)
{
	if (f->name == MANDELBROT)
		return (is_mandelbrot(c, f));
}

void	fractal_render(t_fractal *f)
{
	int	x;
	int	y;
	t_complex	c;
	int color;

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


// void	handle_pixel(int x, int y, t_fractal *fractal)
// {
// 	double new_x;
// 	double new_y;
// 	unsigned int *img_pixel;
// 	t_complex c;
// 	int	color;

// 	new_x = (map(x, 0, WIDTH, -2, 2) * fractal->zoom) + fractal->shiftx;
// 	new_y = (map(y, 0, HEIGHT, -2, 2) * fractal->zoom) + fractal->shifty;
// 	c.real = new_x;
// 	c.imag = new_y;
// 	color = is_mandelbrot(c, fractal);
// 	my_pixel_put(x, y, &fractal->img, color);
// 	// printf("put pixel\n");
// }


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
