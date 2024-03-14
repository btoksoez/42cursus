/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:45:09 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:39:40 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_whitespace(const char *n, int *m)
{
	int	i;

	i = 0;
	while ((n[i] >= 9 && n[i] <= 13) || n[i] == 32)
		i++;
	if (n[i] == '-')
		*m = -1;
	if (n[i] == '-' || n[i] == '+')
		i++;
	return (i);
}

double	ft_atof(const char *n)
{
	int		i;
	int		m;
	double	res;
	double	shift;

	res = 0.0;
	m = 1;
	shift = 0.1;
	i = check_whitespace(n, &m);
	while (n[i] >= '0' && n[i] <= '9')
	{
		res = res * 10.0 + n[i] - '0';
		i++;
	}
	if (n[i] == '.')
		i++;
	while (n[i] >= '0' && n[i] <= '9')
	{
		res = res + (n[i] - '0') * shift;
		shift *= 0.1;
		i++;
	}
	if (n[i] && !ft_isdigit(n[i]))
		return (-42);
	return (res * m);
}
