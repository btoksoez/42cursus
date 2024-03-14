/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:58:26 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:33:36 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* set intitial data for fractal*/
void	data_init(t_fractal *fractal)
{
	fractal->zoom = 1.0;
	fractal->max_iter = 60;
	fractal->threshold = 2.0;
	fractal->box_s = 2.0;
	fractal->box_r = 0.5;
	fractal->box_f = 1.0;
	get_initial_size(fractal);
	init_palette(fractal);
}

/* intialize event hooks */
void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win, KeyPress, KeyPressMask, &key_press, fractal);
	mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask,
		&close_window, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
}

/* intialize mlx, window, image, events and data */
void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		malloc_error();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fractol");
	if (fractal->win == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_len,
			&fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}

/* set initial size in complex plane based on which set */
void	get_initial_size(t_fractal *f)
{
	if (f->name == MANDELBROT)
	{
		f->min_r = -3.0;
		f->max_r = 2.0;
		f->min_i = -3.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}
