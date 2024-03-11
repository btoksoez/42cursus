/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:02:45 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/11 13:48:29 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void zoom(t_fractal *f, double zoom)
{
	//to do
}

static void move(t_fractal *f, double distance, char direction)
{
	//to do
}

int close_window(t_fractal *fr)
{
	printf("Closing Window");
	mlx_destroy_window(fr->mlx, fr->win);
	mlx_destroy_image(fr->mlx, fr->img.img_ptr);
	mlx_destroy_display(fr->mlx);
	free(fr->mlx);
	exit(1);
}

int key_press(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_window(fractal);
	if (keysym == XK_equal)
		fractal->max_iter += 10;
	if (keysym == XK_minus)
		fractal->max_iter -= 10;
	if (keysym == XK_Left)
		fractal->shiftx -= 0.2 * fractal->zoom;
	if (keysym == XK_Right)
		fractal->shiftx += 0.2 * fractal->zoom;
	if (keysym == XK_Up)
		fractal->shifty -= 0.2 * fractal->zoom;
	if (keysym == XK_Down)
		fractal->shifty += 0.2 * fractal->zoom;
	fractal_render(fractal);
}

int mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
	{
		fractal->zoom *= 0.95;
		// fractal->shiftx = map(x, 0, WIDTH, (-2 * fractal->zoom), (2 * fractal->zoom)) + 0.2 * fractal->zoom;
		// fractal->shifty = map(y, 0, HEIGHT, (-2 * fractal->zoom), (2 * fractal->zoom)) + 0.2 * fractal->zoom;
		// fractal->max_iter *= 2;
		fractal_render(fractal);
	}
	if (button == 5)
	{
		fractal->zoom *= 1.05;
		// fractal->shiftx = map(x, 0, WIDTH, -(fractal->zoomx), fractal->zoomx) + fractal->shiftx;
		// fractal->shifty = map(y, 0, HEIGHT, -(fractal->zoomy), fractal->zoomy) + fractal->shifty;
		fractal_render(fractal);
	}
}
