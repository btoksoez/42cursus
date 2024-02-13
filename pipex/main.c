/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:41:24 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/13 14:28:39 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pid1(char *argv[], int pipe_fd[], char *envp[])
{
	int		infile;
	char	*cmd;

	cmd = argv[2];
	infile = open(argv[1], O_RDONLY);
	if ((check_cmd(cmd, envp) || check_infile(argv[1])))
		return ;
	dup2(infile, STDIN_FILENO);
	close(infile);
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd, NULL}, envp);
	perror("Execve1 failed");
	exit(EXIT_FAILURE);
}

void	child_pid2(char *argv[], int pipe_fd[], char *envp[])
{
	int		outfile;
	char	*cmd;

	cmd = argv[3];
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if ((check_cmd(cmd, envp) || check_outfile(argv[4])))
		exit(127);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd, NULL}, envp);
	perror("Execve2 failed");
	exit(EXIT_FAILURE);
}

void	ft_close(int pipe_fd[])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

void	ft_wait(int pid1, int pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipe_fd[2];
	int		pid1;
	int		pid2;

	pid1 = 0;
	if (argc != 5)
		write_err("Wrong input format", 1, 1);
	if (pipe(pipe_fd) == -1)
		write_err("Error opening Pipe", 1, 1);
	pid1 = fork();
	if (pid1 < 0)
		write_err("Error Fork1", 1, 1);
	if (pid1 == 0)
		child_pid1(argv, pipe_fd, envp);
	pid2 = fork();
	if (pid2 < 0)
		write_err("Error Fork2", 1, 1);
	if (pid2 == 0)
		child_pid2(argv, pipe_fd, envp);
	ft_close(pipe_fd);
	ft_wait(pid1, pid2);
}
