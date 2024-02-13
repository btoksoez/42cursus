/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:25:55 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/13 13:31:51 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_infile(char *argv)
{
	if (access(argv, R_OK != 0))
	{
		if (errno == EACCES)
		{
			write_err("permission denied: ", 0, 0);
			write_err(argv, 1, 0);
			return (1);
		}
		else
		{
			write_err("no such file or directory: ", 0, 0);
			write_err(argv, 1, 0);
			return (1);
		}
	}
	return (0);
}

int	check_outfile(char *argv)
{
	if (access(argv, W_OK) != 0)
	{
		if (errno == EACCES)
		{
			write_err("permission denied: ", 0, 0);
			write_err(argv, 1, 0);
			return (1);
		}
		else
		{
			write_err("no such file or directory: ", 0, 0);
			write_err(argv, 1, 0);
			return (1);
		}
	}
	return (0);
}

void	write_err(char *error_message, int new_line, int exit_true)
{
	write(STDERR_FILENO, error_message, ft_strlen(error_message));
	if (new_line == 1)
		write(STDERR_FILENO, "\n", 1);
	if (exit_true)
		exit(EXIT_FAILURE);
	return ;
}
