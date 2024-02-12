/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:26:26 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/12 16:54:12 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_cmds(char *cmd1, char *cmd2)
{
	int error_flag;

	error_flag = 0;
	if (shell_return(cmd1))
	{
		write_err("command not found: ", 0);
		write_err(cmd1, 1);
		error_flag = 1;
	}
	if (shell_return(cmd2))
	{
		write_err("command not found: ", 0);
		write_err(cmd2, 1);
		error_flag = 1;
	}
	if (error_flag)
		exit(EXIT_FAILURE);
}
