/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:02:51 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/25 11:54:31 by btoksoez         ###   ########.fr       */
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
	int		num_philos;
	int		*forks;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_eat;
	int		i;
	pthread_mutex_t	mutex;
	pthread_t	*philos;
}				t_table;

int	ft_atoi(char *str);

#endif
