/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:10:19 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/14 12:40:07 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

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

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_message(char *message, t_philo *philo)
{
	size_t	time_ms;

	pthread_mutex_lock(philo->write_lock);
	time_ms = get_time() - philo->start_time;
	if (!is_dead(philo))
		printf("%zu %d %s\n", time_ms, philo->id, message);
	pthread_mutex_unlock(philo->write_lock);
}

// void print_table(t_table *table)
// {
//     printf("Number of philosophers: %d\n", table->num_philos);
//     printf("Time to die: %zu\n", table->time_to_die);
//     printf("Time to eat: %zu\n", table->time_to_eat);
//     printf("Time to sleep: %zu\n", table->time_to_sleep);
//     printf("Number of times each philosopher must eat: %d\n", table->num_eat);
//     printf("Philosopher died: %s\n", table->philo_died ? "Yes" : "No");

//     for (int i = 0; i < table->num_philos; i++) {
//         printf("Philosopher %d:\n", i);
//         printf("\tID: %d\n", table->philos[i].id);
//         printf("\tNumber of times eaten: %d\n", table->philos[i].num_eaten);
//         printf("\tLast meal: %zu\n", table->philos[i].last_meal);
//         printf("\tStart time: %zu\n", table->philos[i].start_time);
//         printf("\tIs eating: %s\n", table->philos[i].is_eating ? "Yes" : "No");
//         printf("\tIs dead: %s\n", *(table->philos[i].dead) ? "Yes" : "No");
// 		printf("\tLeft fork: %s\n", table->philos[i].left_fork ? "Yes" : "No");
//         printf("\tRight fork: %s\n", table->philos[i].right_fork ? "Yes" : "No");
//         printf("\tDie lock: %s\n", table->philos[i].die_lock ? "Yes" : "No");
//         printf("\tMeal lock: %s\n", table->philos[i].meal_lock ? "Yes" : "No");
//         printf("\tWrite lock: %s\n", table->philos[i].write_lock ? "Yes" : "No");
//     }
// }

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
