/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:01:36 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/02 10:30:35 by btoksoez         ###   ########.fr       */
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
	else
	{
		pthread_mutex_lock(&table->eating_lock);
		philo->is_eating = 1;
		pthread_mutex_unlock(&table->eating_lock);
	}
}

void	philo_eat(t_philosopher *philo, t_table *table)
{
	pthread_mutex_lock(&table->forks[philo->right_fork]);
	print_message("has taken a fork", philo->id, table);
	if (table->num_philos == 1)
	{
		ft_usleep(table->time_to_die);
		pthread_mutex_unlock(&table->forks[philo->right_fork]);
		return ;
	}
	pthread_mutex_lock(&table->forks[philo->left_fork]);
	print_message("has taken a fork", philo->id, table);
	toggle_eating(philo, table);
	print_message("is eating", philo->id, table);
	pthread_mutex_lock(&table->meal_lock);
	philo->last_meal = get_time();
	philo->num_eaten++;
	pthread_mutex_unlock(&table->meal_lock);
	ft_usleep(table->time_to_eat);
	toggle_eating(philo, table);
	pthread_mutex_unlock(&table->forks[philo->left_fork]);
	pthread_mutex_unlock(&table->forks[philo->right_fork]);
}

void	philo_sleep(t_philosopher *philo, t_table *table)
{
	print_message("is sleeping", philo->id, table);
	ft_usleep(table->time_to_sleep);
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

bool	check_death(t_table *table, t_philosopher *philo)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->meal_lock);
		if (get_time() - philo[i].last_meal >= table->time_to_die && !is_eating(philo, table))
		{
			// printf("Start Time: %zu\n", table->start_time);
			// printf("Current Time: %zu\n", get_time());
			// printf("Last Meal Time: %zu\n", philo->last_meal);
			// printf("difference: %zu\n", get_time() - philo->last_meal);
			// printf("Time to die: %zu\n", table->time_to_die);
			// printf("Philosopher ID: %d\n", philo->id);
			print_message("died", philo->id, table);
			pthread_mutex_lock(&table->die_lock);
			table->philo_died = 1;
			pthread_mutex_unlock(&table->die_lock);
			pthread_mutex_unlock(&table->meal_lock);
			return (true);
		}
		pthread_mutex_unlock(&table->meal_lock);
		i++;
	}
	return (false);
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
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!is_dead(table))
	{
		philo_eat(philo, table);
		philo_sleep(philo, table);
		philo_think(philo, table);
	}
	return (NULL);
}

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
		if (check_death(table, table->philos) || all_philos_ate(table))
			break ;
	return (arg);
}

void	start_simulation(t_table *table)
{
	int			i;
	pthread_t	*threads;
	pthread_t	observer;

	threads = malloc(sizeof(pthread_t) * table->num_philos);
	if (!threads)
		return ;
	// create observer thread
	pthread_create(&observer, NULL, &observer_behaviour, table);
	// start threads based on number of philosophers
	i = 0;
	table->start_time = get_time();
	while (i < table->num_philos)
	{
		// create threads
		pthread_create(&threads[i], NULL, &philo_behaviour, &table->philos[i]);
		i++;
	}
	// Wait for threads to finish
	pthread_join(observer, NULL);
	i = 0;
	while (i < table->num_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
    // free threads
	free(threads);
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
	free(table->forks);
	free(table->philos);
	free(table);
}

int main(int argc, char *argv[])
{
	struct s_table	*table;
	if (argc < 5 || argc > 6)
	{
		printf("Usage: %s <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n", argv[0]);
		return (1);
	}
	table = parse_args(argc, argv);
	if (!table)
		return (1);
	init_philos(table);
	init_forks(table);
	// print_table(table);
	start_simulation(table);
	clean_up(table);
}
