/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:25:55 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/19 14:54:09 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_cmd(char *cmd, char *envp[], t_pipex *pipex)
{
	if (shell_return(cmd, envp, pipex) != 0
		&& shell_return(cmd, envp, pipex) != 256
		&& shell_return(cmd, envp, pipex) != 512)
	{
		write_err("command not found: ", 0, 0, NULL);
		write_err(cmd, 1, 0, NULL);
		return (1);
	}
	return (0);
}

int	check_infile(char *argv)
{
	if (access(argv, R_OK) != 0)
	{
		if (errno == EACCES)
		{
			write_err("permission denied: ", 0, 0, NULL);
			write_err(argv, 1, 0, NULL);
			return (1);
		}
		else if (errno == ENOENT)
		{
			write_err("no such file or directory: ", 0, 0, NULL);
			write_err(argv, 1, 0, NULL);
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
			write_err("permission denied: ", 0, 0, NULL);
			write_err(argv, 1, 0, NULL);
			return (1);
		}
		else if (errno == ENOENT)
		{
			write_err("no such file or directory: ", 0, 0, NULL);
			write_err(argv, 1, 0, NULL);
			return (1);
		}
	}
	return (0);
}

void	write_err(char *message, int new_line, int exit_code, t_pipex *pipex)
{
	if (message)
		write(STDERR_FILENO, message, ft_strlen(message));
	if (new_line == 1)
		write(STDERR_FILENO, "\n", 1);
	if (pipex)
		ft_close(pipex);
	if (exit_code)
		exit(exit_code);
	return ;
}
