/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:06:32 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/21 16:18:23 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"


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
		ft_printf("Wrong input format\n");
}
