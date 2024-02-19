/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stderr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:05:08 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/12 11:15:33 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_stderror(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

char	**argsdup(int argc, char *argv[])
{
	char	**res;
	int		i;

	i = 1;
	res = (char **)malloc(sizeof(char *) * argc);
	if (!res)
		return (NULL);
	while (i < argc)
	{
		res[i - 1] = ft_strdup(argv[i]);
		if (!res[i - 1])
		{
			while (--i >= 0)
				free(res[i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i - 1] = NULL;
	return (res);
}

void	free_arr(char **res)
{
	int	i;

	if (!res)
		return ;
	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
}
