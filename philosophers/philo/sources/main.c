/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:01:36 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/25 11:56:17 by btoksoez         ###   ########.fr       */
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
	table->num_philos = ft_atoi(argv[1]);
	table->forks = malloc(sizeof(int) * table->num_philos);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->philos = malloc(sizeof(pthread_t) * table->num_philos);
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

void	print_table(t_table *table)
{
	int	i;

	printf("Number of philosophers: %d\n", table->num_philos);
	i = 0;
	while (i < table->num_philos)
		printf("Forks: %d\n", table->forks[i++]);
	printf("Time to die: %d\n", table->time_to_die);
	printf("Time to eat: %d\n", table->time_to_eat);
	printf("Time to sleep: %d\n", table->time_to_sleep);
	if (table->num_eat != -1)
		printf("Number of times each philosopher must eat: %d\n", table->num_eat);

}

void	*threadFunction(t_table *table)
{
	int begin_last_meal;
	struct timeval tv;

	//sleep
	usleep(table->time_to_sleep);
	// eat
    gettimeofday(&tv, NULL);
	begin_last_meal = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	pthread_mutex_lock(&table->mutex);
	table->forks[table->i] = 1;
	usleep(table->time_to_eat);
	table->forks[table->i] = 0;
	pthread_mutex_unlock(&table->mutex);
	// think
	gettimeofday(&tv, NULL);
	if (begin_last_meal > table->time_to_die)
	{
		printf("Philosopher %d died\n", table->i);
		pthread_exit(NULL);
	}
	//check if dead
	return ;
}

void	start(t_table *table)
{
	int			i;

	// init mutex
	pthread_mutex_init(&table->mutex, NULL);
	// start threads based on number of philosophers
	while (table->i < table->num_philos)
	{
		// create thread
		pthread_create(&table->philos[i], NULL, threadFunction, table);
		table->i++;
	}
	// Wait for threads to finish
	i = 0;
	while (i < table->num_philos)
	{
		pthread_join(table->philos[i], NULL);
		i++;
	}
    // Destroy mutex
    pthread_mutex_destroy(&table->mutex);

}

void	clean_up(t_table *table)
{
	if (!table)
		return ;
	free(table->forks);
	free(table->philos);
	free(table);
	table = NULL;
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
	print_table(table);
	start(table);
	clean_up(table);
}
