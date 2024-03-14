/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:19:34 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/13 13:29:55 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_palette(t_fractal *fractal)
{
	int	i;

	i = 0;
	while (i < PALETTE_SIZE)
	{
		fractal->palette[i] = get_gradient(GRAD_START, GRAD_END, i);
		i++;
	}
}

/*extracts rgb from colors and calculates based on
step the gradient uses shifting to extract right color and
& 0xFF operation to make everything else to 0 */
int	get_gradient(int startColor, int endColor, int steps)
{
	t_rgb	start;
	t_rgb	end;
	t_rgb	gradient;

	start.red = (startColor >> 16) & 0xFF;
	start.green = (startColor >> 8) & 0xFF;
	start.blue = startColor & 0xFF;
	end.red = (endColor >> 16) & 0xFF;
	end.green = (endColor >> 8) & 0xFF;
	end.blue = endColor & 0xFF;
	gradient.red = start.red + (end.red - start.red) * steps / 255;
	gradient.green = start.green + (end.green - start.green) * steps / 255;
	gradient.blue = start.blue + (end.blue - start.blue) * steps / 255;
	return ((gradient.red << 16) | (gradient.green << 8) | gradient.blue);
}
