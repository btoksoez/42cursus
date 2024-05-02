/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:28:11 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/02 10:49:06 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_table(t_table *table)
{
	//maybe add protection for max philosophers
	if (table->num_philos < 1 || table->num_eat > 200 || table->num_eat < -1)
	{
		clean_up(table);
		return (false);
	}
	return (true);
}

/* parses arguments into a table struct */
t_table	*parse_args(int argc, char *argv[])
{
	t_table	*table;

	if (!check_args(argc, argv))
	{
		printf("Error: invalid arguments\n");
		return (NULL);
	}
	table = malloc(sizeof(t_table));
	if (!table)
	{
		printf("Error: malloc failed\n");
		return (NULL);
	}
	init_table(table);
	table->num_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->num_eat = ft_atoi(argv[5]);
	else
		table->num_eat = -1;
	if (!check_table(table))
	{
		printf("Error: invalid table\n");
		return (NULL);
	}
	return (table);
}
