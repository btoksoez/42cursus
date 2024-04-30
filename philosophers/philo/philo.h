/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:02:51 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/30 22:57:50 by btoksoez         ###   ########.fr       */
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
	size_t					time_to_die;
	size_t					time_to_eat;
	size_t					time_to_sleep;
	int						num_eat;
	int						i;
	pthread_mutex_t			*forks;
	pthread_mutex_t			die_lock;
	pthread_mutex_t			meal_lock;
	pthread_mutex_t			eating_lock;
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
	size_t	last_meal;
	int		is_eating;
	t_table	*table;
}				t_philosopher;

/*--------------------init--------------------*/
void	init_forks(t_table *table);
void	init_table(t_table *table);
void	init_philos(t_table *table);

/*-------------------parsing------------------*/
t_table	*parse_args(int argc, char *argv[]);
bool	check_table(t_table *table);
bool	check_args(int argc, char *argv[]);


bool	is_dead(t_table *table);

/*--------------------main--------------------*/
void	clean_up(t_table *table);

/*--------------------utils--------------------*/
long	get_time(void);
int		ft_atoi(char *str);
void	print_message(char *message, int id, t_table *table);
void	print_table(t_table *table);

#endif
