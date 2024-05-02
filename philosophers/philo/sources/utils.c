/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:10:19 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/02 10:23:43 by btoksoez         ###   ########.fr       */
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

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	print_message(char *message, int id, t_table *table)
{
	long	time_ms;

	pthread_mutex_lock(&table->info_lock);
	time_ms = get_time() - table->start_time;
	if (!is_dead(table))
		printf("%ld %d %s\n", time_ms, id, message);
	pthread_mutex_unlock(&table->info_lock);
}

void print_table(t_table *table)
{
    printf("Number of philosophers: %d\n", table->num_philos);
    printf("Time to die: %zu\n", table->time_to_die);
    printf("Time to eat: %zu\n", table->time_to_eat);
    printf("Time to sleep: %zu\n", table->time_to_sleep);
    printf("Number of times each philosopher must eat: %d\n", table->num_eat);

    for (int i = 0; i < table->num_philos; i++) {
        printf("Philosopher %d:\n", i);
        printf("\tID: %d\n", table->philos[i].id);
        printf("\tLeft fork: %d\n", table->philos[i].left_fork);
        printf("\tRight fork: %d\n", table->philos[i].right_fork);
        printf("\tNumber of times eaten: %d\n", table->philos[i].num_eaten);
    }
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return(0);
}
