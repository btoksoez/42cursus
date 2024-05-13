/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:35:27 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/13 15:25:28 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_eat(t_philosopher *philo, t_table *table)
{
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo->id, table);
	if (table->num_philos == 1)
	{
		ft_usleep(table->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo->id, table);
	toggle_eating(philo, table);
	print_message("is eating", philo->id, table);
	pthread_mutex_lock(&table->meal_lock);
	philo->last_meal = get_time();
	philo->num_eaten++;
	pthread_mutex_unlock(&table->meal_lock);
	ft_usleep(table->time_to_eat);
	toggle_eating(philo, table);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleep(t_philosopher *philo, t_table *table)
{
	print_message("is sleeping", philo->id, table);
	ft_usleep(table->time_to_sleep);
}

void	philo_think(t_philosopher *philo, t_table *table)
{
	print_message("is thinking", philo->id, table);
}

void	*philo_behaviour(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;

	philo = (t_philosopher *)arg;
	table = philo->table;
	// if (philo->id % 2 == 0)
	// 	ft_usleep(0);
	while (!is_dead(table))
	{
		philo_eat(philo, table);
		philo_sleep(philo, table);
		philo_think(philo, table);
	}
	return (NULL);
}

void	start_simulation(t_table *table)
{
	int			i;
	pthread_t	*threads;
	pthread_t	observer;

	threads = malloc(sizeof(pthread_t) * table->num_philos);
	if (!threads)
		return ;
	pthread_create(&observer, NULL, &observer_behaviour, table);
	i = 0;
	while (i < table->num_philos)
	{
		pthread_create(&threads[i], NULL, &philo_behaviour, &table->philos[i]);
		i++;
	}
	pthread_join(observer, NULL);
	i = 0;
	while (i < table->num_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}
