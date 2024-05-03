/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:24:29 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/03 12:36:06 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_forks(t_table *table)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	table->forks = forks;
}

void	init_philos(t_table *table)
{
	int				i;
	t_philosopher	*philo;

	philo = malloc(sizeof(t_philosopher) * table->num_philos);
	if (!philo)
	{
		printf("Error: malloc failed\n");
		return ;
	}
	i = 0;
	while (i < table->num_philos)
	{
		philo[i].id = i + 1;
		philo[i].right_fork = i;
		if (i == 0)
			philo[i].left_fork = table->num_philos - 1;
		else
			philo[i].left_fork = i - 1;
		philo[i].num_eaten = 0;
		philo[i].last_meal = get_time();
		philo[i].table = table;
		philo[i].is_eating = 0;
		i++;
	}
	table->philos = philo;
}

void	init_table(t_table *table)
{
	table->num_philos = 0;
	table->time_to_die = 0;
	table->time_to_eat = 0;
	table->time_to_sleep = 0;
	table->num_eat = 0;
	table->forks = NULL;
	table->philos = NULL;
	table->start_time = get_time();
	table->philo_died = 0;
	pthread_mutex_init(&table->die_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
	pthread_mutex_init(&table->eating_lock, NULL);
	pthread_mutex_init(&table->info_lock, NULL);
}
