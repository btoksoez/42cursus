/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:06:32 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/12 13:53:59 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fractol.h"

void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
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

int main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (!parse_args(argc, argv, &fractal))
		return (1);
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx);
}



//sort main function

//add ft_printf and ft_atof...
//add mandelbox
//improve color
//o smooth out the contours between colors, we can subtract a fractional amount: log2(log2|z|) from the iteration count to give a more continuous result, as shown above. It can also help to first perform an extra iteration or two after z escapes.
//check https://github.com/GlThibault/Fractol/?source=post_page-----6664b6b045b5--------------------------------

