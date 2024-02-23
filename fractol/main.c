/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:06:32 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/23 18:33:58 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fractol.h"



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
	{
		close_window(fractal);
	}
}

int mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
	{
		fractal->zoomx = fractal->zoomx * 0.8 + map(x, 0, WIDTH, -(fractal->zoomx), fractal->zoomx);
		fractal->zoomy = fractal->zoomy * 0.8 + map(y, 0, HEIGHT, -(fractal->zoomy), fractal->zoomy);
		printf("zoom in\n");
		printf("zoom: %f\n", fractal->zoomx);
		fractal->max_iter *= 2;
		fractal_render(fractal);
		//map stuff is wrong
		//first let user scroll, wait until no movement, then recalculate image?
		//increase iterations with zoom
	}
	if (button == 5)
	{
		fractal->zoomx = fractal->zoomx * 1.2 + map(x, 0, WIDTH, -(fractal->zoomx), fractal->zoomx);;
		fractal->zoomy = fractal->zoomy * 1.2 + map(y, 0, HEIGHT, -(fractal->zoomy), fractal->zoomy);
		printf("zoom out\n");
		fractal_render(fractal);
	}
}

void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->zoomx = 2;
	fractal->zoomy = 2;
	fractal->max_iter = 100;	//the more iterations, the clearer the mandelbrot set, because pixels on the limit
	fractal->threshold = 2.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win, KeyPress, KeyPressMask, &key_press, fractal);
	mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, &close_window, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		malloc_error();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
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

void	ft_mandelbrot(void)
{
	t_fractal	fractal;

	fractal.name = "Mandelbrot";
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx);
}

void	ft_julia(char *ag1, char *arg2)
{
	return ;
}
//calculate for all pixels in image if they are in mandelbrot set or not
	// if yes certain color
	// if not different color
	//project pixels
	//make zoom possible
		//first render only certain amount of pixels (every 5th or so?)
		//then render more in zoomed in area

int main(int argc, char *argv[])
{
	if (argc == 4 && ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
		ft_julia(argv[2], argv[3]);
	else if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
		ft_mandelbrot();
	else
		printf("Wrong input format\n");
}
