/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:29:50 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/19 14:57:14 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(t_pipex *pipex)
{
	if (pipex->pipe_fd[0] != -1)
		close(pipex->pipe_fd[0]);
	if (pipex->pipe_fd[1] != -1)
		close(pipex->pipe_fd[1]);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	if (pipex->dev_null != -1)
		close(pipex->dev_null);
	free(pipex);
}

void	ft_wait(int pid1, int pid2)
{
	int	status1;
	int	status2;

	status1 = 0;
	status2 = 0;
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (status1 == 25600)
		exit(1);
	if ((status1 == 12800 && status2 == 12800)
		|| (status1 == 36096 && status2 == 12800))
		exit(127);
	if (status1 == 256 || status2 == 256)
		exit(1);
	if (status2 == 512)
		exit(2);
}
