/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:25:55 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/12 17:01:44 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_errors(char *argv[], int infile, int outfile)
{
	int error_flag;

	error_flag = 0;
	error_flag = check_infile(argv, infile);
	error_flag = check_outfile(argv, outfile);
	if (error_flag)
		exit(EXIT_FAILURE);
}

int	check_infile(char *argv[], int infile)
{
	if (infile == -1)
	{
		write_err("no such file or directory: ", 0);
		write_err(argv[1], 1);
		return (1);
	}
	else if (access(argv[1], R_OK) != 0 && infile > 0)
	{
		write_err("permission denied: ", 0);
		write_err(argv[1], 1);
		return (1);
	}
	return (0);
}

int check_outfile(char *argv[], int outfile)
{
	if (outfile == -1)
	{
		if (access(argv[4], W_OK) != 0)
		{
			write_err("permission denied: ", 0);
			write_err(argv[4], 1);
			return (1);
		}
		write_err("no such file or directory: ", 0);
		write_err(argv[4], 1);
		return (1);
	}
	return (0);
}

void	write_err(char *error_message, int new_line)
{
	write(STDERR_FILENO, error_message, ft_strlen(error_message));
	if (new_line == 1)
		write(STDERR_FILENO, "\n", 1);
}


//fic check infile: needs to return right values for different inputs

