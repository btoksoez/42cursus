/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:17:30 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/21 14:16:30 by btoksoez         ###   ########.fr       */
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
	if (ft_atof(argv[2]) > 2.0 || ft_atof(argv[2]) < -2.0)
		return (help_message(0));
	if (ft_atof(argv[3]) >= 2.0 || ft_atof(argv[3]) <= -2.0)
		return (help_message(0));
	return (1);
}

int	check_julia(int argc, char *argv[], t_fractal *fractal)
{
	if (check_julia_params(argv))
	{
		fractal->name = 2;
		fractal->julia_c.real = ft_atof(argv[2]);
		fractal->julia_c.imag = ft_atof(argv[3]);
		fractal_fast(argc, argv, fractal);
		return (1);
	}
	else
		return (0);
}

int	fractal_fast(int argc, char *argv[], t_fractal *fractal)
{
	if ((argc == 3 && ft_strncmp(argv[2], "fast", ft_strlen(argv[2])) == 0)
		|| (argc == 5 && ft_strncmp(argv[4], "fast", ft_strlen(argv[2])) == 0))
		fractal->fast = 1;
	else if (argc == 3 || argc == 5)
		return (help_message(0));
	else
		fractal->fast = 0;
	return (1);
}

/* checks which set and if number of args is correct & assigns color */
int	parse_args(int argc, char *argv[], t_fractal *fractal)
{
	if ((argc == 4 || argc == 5)
		&& ft_strncmp(argv[1], "julia", 5) == 0
		&& ft_strlen(argv[1]) == 5)
	{
		if (!check_julia(argc, argv, fractal))
			return (0);
	}
	else if ((argc == 2 || argc == 3)
		&& ft_strncmp(argv[1], "mandelbrot", 10) == 0
		&& ft_strlen(argv[1]) == 10)
	{
		fractal->name = 1;
		return (fractal_fast(argc, argv, fractal));
	}
	else if ((argc == 2 || argc == 3)
		&& ft_strncmp(argv[1], "mandelbox", 9) == 0
		&& ft_strlen(argv[1]) == 9)
	{
		fractal->name = 3;
		return (fractal_fast(argc, argv, fractal));
	}
	else
		return (help_message(0));
	return (1);
}

/* prints help message */
int	help_message(int n)
{
	ft_printf("*************************************************************\n");
	ft_printf("*                      Fractol Help                         *\n");
	ft_printf("*************************************************************\n");
	ft_printf("* Usage:                                                    *\n");
	ft_printf("*   ./fractol mandelbrot {fast}                             *\n");
	ft_printf("*   ./fractol mandelbox {fast}                             *\n");
	ft_printf("*   ./fractol julia {real number} {imaginary number} {fast} *\n");
	ft_printf("*     (Both numbers must be in the range [-2.0, 2.0])       *\n");
	ft_printf("*     (fast is optional, differen colors)                   *\n");
	ft_printf("*                                                           *\n");
	ft_printf("* Controls:                                                 *\n");
	ft_printf("*   Scroll: Zoom in and out                                 *\n");
	ft_printf("*   - : Decrease resolution (max iterations)                *\n");
	ft_printf("*   + : Increase resolution (max iterations)                *\n");
	ft_printf("*   Arrow keys: Move around                                 *\n");
	ft_printf("*************************************************************\n");
	return (n);
}
