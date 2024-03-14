/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:17:30 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 12:14:44 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* check if float numbers and if between -2 and 2 */
int	check_julia_params(char *argv[])
{
	if (!ft_strchr(argv[2], '.'))
		return (help_message(0));
	if (!ft_strchr(argv[3], '.'))
		return (help_message(0));
	if (atof(argv[2]) > 2.0 || atof(argv[2]) < -2.0)
		return (help_message(0));
	if (atof(argv[3]) >= 2.0 || atof(argv[3]) <= -2.0)
		return (help_message(0));
	return (1);
}

int	check_julia(int argc, char *argv[], t_fractal *fractal)
{
	if (check_julia_params(argv))
	{
		fractal->name = 2;
		fractal->julia_c.real = atof(argv[2]);
		fractal->julia_c.imag = atof(argv[3]);
		if (argc == 5 && ft_strncmp(argv[4], "fast", 4) == 0)
			fractal->fast = 1;
		return (1);
	}
	else
		return (0);
}

/* checks which set and if number of args is correct & assigns color */
int	parse_args(int argc, char *argv[], t_fractal *fractal)
{
	if ((argc == 4 || argc == 5)
		&& ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
	{
		if (!check_julia(argc, argv, fractal))
			return (0);
	}
	else if ((argc == 2 || argc == 3)
		&& ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
	{
		fractal->name = 1;
		if (argc == 3 && ft_strncmp(argv[2], "fast", 4) == 0)
			fractal->fast = 1;
	}
	else if ((argc == 2 || argc == 3)
		&& ft_strncmp(argv[1], "mandelbox", ft_strlen(argv[1])) == 0)
	{
		fractal->name = 3;
		if (argc == 3 && ft_strncmp(argv[2], "fast", 4) == 0)
			fractal->fast = 1;
	}
	else
		return (help_message(0));
	return (1);
}

/* prints help message */
int	help_message(int n)
{
	printf("*************************************************************\n");
	printf("*                      Fractol Help                         *\n");
	printf("*************************************************************\n");
	printf("* Usage:                                                    *\n");
	printf("*   ./fractol mandelbrot {fast}                             *\n");
	printf("*   ./fractol mandelbox {fast}                             *\n");
	printf("*   ./fractol julia {real number} {imaginary number} {fast} *\n");
	printf("*     (Both numbers must be in the range [-2.0, 2.0])       *\n");
	printf("*     (fast is optional, differen colors)                   *\n");
	printf("*                                                           *\n");
	printf("* Controls:                                                 *\n");
	printf("*   Scroll: Zoom in and out                                 *\n");
	printf("*   - : Decrease resolution (max iterations)                *\n");
	printf("*   + : Increase resolution (max iterations)                *\n");
	printf("*   Arrow keys: Move around                                 *\n");
	printf("*************************************************************\n");
	return (n);
}
