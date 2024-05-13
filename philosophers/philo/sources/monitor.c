/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:39:04 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/13 15:26:17 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	all_philos_ate(t_table *table)
{
	int	i;

	i = 0;
	if (table->num_eat == -1)
		return (false);
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->meal_lock);
		if (table->philos[i].num_eaten < table->num_eat)
			return (pthread_mutex_unlock(&table->meal_lock), false);
		i++;
		pthread_mutex_unlock(&table->meal_lock);
	}
	pthread_mutex_lock(&table->die_lock);
	table->philo_died = 1;
	pthread_mutex_unlock(&table->die_lock);
	return (true);
}

void	*observer_behaviour(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (check_if_dead(table) || all_philos_ate(table))
			break ;
	}
	return (arg);
}

bool	is_dead(t_table *table)
{
	pthread_mutex_lock(&table->die_lock);
	if (table->philo_died)
	{
		pthread_mutex_unlock(&table->die_lock);
		return (true);
	}
	pthread_mutex_unlock(&table->die_lock);
	return (false);
}

bool	is_eating(t_philosopher *philo, t_table *table)
{
	pthread_mutex_lock(&table->eating_lock);
	if (philo->is_eating)
		return (pthread_mutex_unlock(&table->eating_lock), true);
	return (pthread_mutex_unlock(&table->eating_lock), false);
}

bool	philo_dead(t_table *table, t_philosopher *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_time() - philo->last_meal >= table->time_to_die
		&& philo->is_eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), true);
	pthread_mutex_unlock(philo->meal_lock);
	return (false);
}

bool	check_if_dead(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		if (philo_dead(table, &table->philos[i]))
		{
			print_message("died", table->philos[i].id, table);
			pthread_mutex_lock(table->philos[i].die_lock);
			table->philo_died = 1;
			pthread_mutex_unlock(table->philos[i].die_lock);
			return (true);
		}
		i++;
	}
	return (false);
}

// bool	check_death(t_table *table, t_philosopher *philo)
// {
// 	int	i;

// 	i = 0;
// 	while (i < table->num_philos)
// 	{
// 		pthread_mutex_lock(&table->meal_lock);
// 		if (get_time() - philo[i].last_meal >= table->time_to_die
// 			&& !is_eating(&philo[i], table))
// 		{
// 			// printf("Start Time: %zu\n", table->start_time);
// 			// printf("Current Time: %zu\n", get_time());
// 			// printf("Last Meal Time: %zu\n", philo->last_meal);
// 			// printf("difference: %zu\n", get_time() - philo->last_meal);
// 			// printf("Time to die: %zu\n", table->time_to_die);
// 			// printf("Philosopher ID: %d\n", philo->id);
// 			print_message("died", philo[i].id, table);
// 			pthread_mutex_lock(&table->die_lock);
// 			table->philo_died = 1;
// 			pthread_mutex_unlock(&table->die_lock);
// 			pthread_mutex_unlock(&table->meal_lock);
// 			return (true);
// 		}
// 		pthread_mutex_unlock(&table->meal_lock);
// 		i++;
// 	}
// 	return (false);
// }
