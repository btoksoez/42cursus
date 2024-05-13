/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:41:24 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/12 13:07:15 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pid1(char *argv[], t_pipex *pipex, char *envp[])
{
	char	*cmd;

	cmd = argv[2];
	pipex->infile = open(argv[1], O_RDONLY);
	if (check_infile(argv[1]))
		write_err(NULL, 0, 100, pipex);
	if (check_cmd(cmd, envp, pipex))
		write_err(NULL, 0, 50, pipex);
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->infile);
	close(pipex->pipe_fd[0]);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->pipe_fd[1]);
	execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd, NULL}, envp);
	write_err("Execve1 failed", 1, 1, pipex);
}

void	child_pid2(char *argv[], t_pipex *pipex, char *envp[])
{
	char	*cmd;

	cmd = argv[3];
	pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (check_outfile(argv[4]))
		write_err(NULL, 0, 5, pipex);
	if (check_cmd(cmd, envp, pipex))
		write_err(NULL, 0, 50, pipex);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->outfile);
	close(pipex->pipe_fd[1]);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[0]);
	execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd, NULL}, envp);
	write_err("Execve2 failed", 1, 1, pipex);
}

t_pipex	*initialize_pipex(void)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		write_err("malloc pipex failed", 1, 1, NULL);
	pipex->infile = 3;
	pipex->outfile = 3;
	pipex->pipe_fd[0] = 3;
	pipex->pipe_fd[1] = 3;
	pipex->dev_null = 3;
	return (pipex);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;
	int		pid1;
	int		pid2;

	if (argc != 5)
		write_err("Wrong input format", 1, 1, NULL);
	pipex = initialize_pipex();
	if (pipe(pipex->pipe_fd) == -1)
		write_err("Error opening Pipe", 1, 1, pipex);
	pid1 = fork();
	if (pid1 < 0)
		write_err("Error Fork1", 1, 1, pipex);
	if (pid1 == 0)
		child_pid1(argv, pipex, envp);
	pid2 = fork();
	if (pid2 < 0)
		write_err("Error Fork2", 1, 1, pipex);
	if (pid2 == 0)
		child_pid2(argv, pipex, envp);
	ft_close(pipex);
	ft_wait(pid1, pid2);
}
