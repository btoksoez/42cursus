/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:02:51 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/26 15:27:49 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_table
{
	int						num_philos;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						num_eat;
	int						i;
	pthread_mutex_t			*forks;
	pthread_mutex_t			die_lock;
	struct s_philosopher	*philos;
	long					start_time;
	int						philo_died;
}							t_table;

typedef struct s_philosopher
{
	int		id;
	int		left_fork;
	int		right_fork;
	int		num_eaten;
	t_table	*table;
}				t_philosopher;

int		ft_atoi(char *str);
void	clean_up(t_table *table);
long	get_time(void);
void	init_table(t_table *table);
bool	is_dead(t_table *table);

#endif
