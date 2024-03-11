/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:06:32 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/11 13:45:16 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fractol.h"

void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->zoom = 1.0;
	fractal->max_iter = 60;	//the more iterations, the clearer the mandelbrot set, because pixels on the limit
	fractal->threshold = 2.0;
	fractal->shiftx = 0;
	fractal->shifty = 0;
	get_initial_size(fractal);
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
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

void	ft_mandelbrot(void)
{
	t_fractal	fractal;

	fractal.name = MANDELBROT;
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




//add zoom
//correct shifting etc.

//add julia
//add threads?
//check https://github.com/GlThibault/Fractol/?source=post_page-----6664b6b045b5--------------------------------

