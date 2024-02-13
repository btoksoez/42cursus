/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:26:26 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/13 13:32:14 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_errors(char *argv[], char *cmd1, char *cmd2)
{
	int	error_1;
	int	error_2;

	error_1 = 0;
	error_2 = 0;
	error_1 += check_cmd(cmd1);
	error_1 += check_infile(argv[1]);
	error_2 += check_cmd(cmd2);
	error_2 += check_outfile(argv[4]);
	if (error_2)
		exit_reason(127);
	if (error_1)
		return (1);
	return (0);
}

int	check_cmd(char *cmd)
{
	if (shell_return(cmd) != 0 && shell_return(cmd) != 256
		&& shell_return(cmd) != 512)
	{
		write_err("command not found: ", 0, 0);
		write_err(cmd, 1, 0);
		return (1);
	}
	return (0);
}
