/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:06:32 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

int	close_window(t_fractal *fr)
{
	ft_printf("Closing Window");
	mlx_destroy_window(fr->mlx, fr->win);
	mlx_destroy_image(fr->mlx, fr->img.img_ptr);
	mlx_destroy_display(fr->mlx);
	free(fr->mlx);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (!parse_args(argc, argv, &fractal))
		return (1);
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
