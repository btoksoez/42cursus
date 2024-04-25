/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:10:19 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/25 11:11:39 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int ft_atoi(char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	if (!str)
		return (0);
	while (str[i] >= ' ' && str[i] <= '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
