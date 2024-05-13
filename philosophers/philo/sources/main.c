/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:01:36 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/13 14:51:18 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	toggle_eating(t_philosopher *philo, t_table *table)
{
	if (philo->is_eating)
	{
		pthread_mutex_lock(&table->eating_lock);
		philo->is_eating = 0;
		pthread_mutex_unlock(&table->eating_lock);
	}
	else if (!philo->is_eating)
	{
		pthread_mutex_lock(&table->eating_lock);
		philo->is_eating = 1;
		pthread_mutex_unlock(&table->eating_lock);
	}
}

void	clean_up(t_table *table)
{
	int	i;

	i = 0;
	if (!table)
		return ;
	while (i < table->num_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->die_lock);
	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->eating_lock);
	pthread_mutex_destroy(&table->info_lock);
	pthread_mutex_destroy(&table->forks_lock);
	free(table->forks);
	free(table->philos);
	free(table);
}

int	main(int argc, char *argv[])
{
	struct s_table	*table;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: %s <number_of_philosophers> <time_to_die> <time_to_eat>\
<time_to_sleep> [number_of_times_each_philosopher_must_eat]\n", argv[0]);
		return (1);
	}
	table = parse_args(argc, argv);
	if (!table)
		return (1);
	init_forks(table);
	init_philos(table);
	// print_table(table);
	start_simulation(table);
	clean_up(table);
}
