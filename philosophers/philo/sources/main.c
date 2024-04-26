/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:01:36 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/26 15:41:56 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* checks whether given args are numbers, might need to add to check for their relationship to each other */
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
	if (table->num_philos < 2)
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

void	init_table(t_table *table)
{
	table->num_philos = 0;
	table->time_to_die = 0;
	table->time_to_eat = 0;
	table->time_to_sleep = 0;
	table->num_eat = 0;
	table->forks = NULL;
	table->philos = NULL;
	table->start_time = 0;
	table->philo_died = 0;
	pthread_mutex_init(&table->die_lock, NULL);
}

void print_table(t_table *table) {
    printf("Number of philosophers: %d\n", table->num_philos);
    printf("Time to die: %d\n", table->time_to_die);
    printf("Time to eat: %d\n", table->time_to_eat);
    printf("Time to sleep: %d\n", table->time_to_sleep);
    printf("Number of times each philosopher must eat: %d\n", table->num_eat);

    for (int i = 0; i < table->num_philos; i++) {
        printf("Philosopher %d:\n", i);
        printf("\tID: %d\n", table->philos[i].id);
        printf("\tLeft fork: %d\n", table->philos[i].left_fork);
        printf("\tRight fork: %d\n", table->philos[i].right_fork);
        printf("\tNumber of times eaten: %d\n", table->philos[i].num_eaten);
    }
}

void	print_message(char *message, int id, t_table *table)
{
	long	time_ms;

	time_ms = get_time() - table->start_time;
	printf("%ld Philosopher %d %s\n", time_ms, id, message);
}

void	philo_eat(t_philosopher *philo, t_table *table)
{
	if (is_dead(table))
		return ;
	if (pthread_mutex_lock(&table->forks[philo->left_fork]) == 0 && !is_dead(table))
	{
		print_message("has taken a fork", philo->id, table);
		// If the left fork is available, try to pick up the right fork
		if (pthread_mutex_lock(&table->forks[philo->right_fork]) == 0 && !is_dead(table))
		{
			print_message("has taken a fork", philo->id, table);
			// If the right fork is available, eat
			print_message("is eating", philo->id, table);
			usleep(table->time_to_eat * 1e3);
			// Put down the right fork
			pthread_mutex_unlock(&table->forks[philo->right_fork]);
		}
		// Put down the left fork
		pthread_mutex_unlock(&table->forks[philo->left_fork]);
	}
}

void	philo_sleep(t_philosopher *philo, t_table *table)
{
	if (is_dead(table))
		return ;
	print_message("is sleeping", philo->id, table);
	usleep(table->time_to_sleep * 1e3);
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


bool	check_death(t_table *table, t_philosopher *philo)
{
	if ((get_time() - table->start_time) > table->time_to_die)
	{
		pthread_mutex_lock(&table->die_lock);
		table->philo_died = 1;
		pthread_mutex_unlock(&table->die_lock);
		print_message("died", philo->id, table);
		return (true);
	}
	return (false);
}


void	*philo_behaviour(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;

	philo = (t_philosopher *)arg;
	table = philo->table;
	while (1)
	{
		if (is_dead(table))
			break ;
		philo_eat(philo, table);
		if (table->num_eat != -1)
		{
			philo->num_eaten++;
			if (philo->num_eaten >= table->num_eat)
				break ;
		}
		if (is_dead(table))
			break ;
		philo_sleep(philo, table);
		if (is_dead(table))
			break ;
		print_message("is thinking", philo->id, table);
		// printf("current time - start time: %ld\ntable time to die: %d", get_time() - table->start_time, table->time_to_die);
		if (check_death(table, philo))
			break ;
	}
	return (NULL);
}

long	get_time(void)
{
	struct timeval	tv;
	long			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec * 1e6 + tv.tv_usec) / 1e3;
	return (time_ms);
}

void	start_simulation(t_table *table)
{
	int			i;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * table->num_philos);
	if (!threads)
		return ;
	// start threads based on number of philosophers
	i = 0;
	table->start_time = get_time();
	while (i < table->num_philos)
	{
		// create threads
		pthread_create(&threads[i], NULL, philo_behaviour, &table->philos[i]);
		i++;
	}
	// Wait for threads to finish
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
	free(table->forks);
	free(table->philos);
	free(table);
	table->forks = NULL;
	table->philos = NULL;
	table = NULL;
}

void	init_forks(t_table *table)
{
	int	i;
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
		if (i == 0)	//to avoid deadlock, the first one should pick up the right fork first
		{
			philo[i].right_fork = i;
			philo[i].left_fork = (i + 1) % table->num_philos;
		}
		else
		{
			philo[i].left_fork = i;
			philo[i].right_fork = (i + 1) % table->num_philos;
		}
		philo[i].num_eaten = 0;
		philo[i].table = table;
		i++;
	}
	table->philos = philo;
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
	print_table(table);
	start_simulation(table);
	print_table(table);
	clean_up(table);
}
