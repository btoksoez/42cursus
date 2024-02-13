/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:41:24 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/13 13:29:12 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pid1(int infile, char *cmd, int pipe_fd[], char *envp[])
{
	dup2(infile, STDIN_FILENO);
	close(infile);
	close(pipe_fd[0]); //close read end of pipe
	dup2(pipe_fd[1], STDOUT_FILENO); //reroute stdout to write end of pipe
	close(pipe_fd[1]);
	execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd, NULL}, envp);
	perror("Execve1 failed");
	exit(EXIT_FAILURE);
}

void	child_pid2(int outfile, char *cmd, int pipe_fd[], char *envp[])
{
	//close write end of pipe
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO); //reroute stdin to read end of pipe
	close(pipe_fd[0]);
	execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd, NULL}, envp);
	perror("Execve2 failed");
	exit(EXIT_FAILURE);
}

void	ft_close(int infile, int outfile, int pipe_fd[])
{
	close(infile);
	close(outfile);
	close(pipe_fd[0]);	//close for parent process
	close(pipe_fd[1]);
}

void	ft_wait(int pid1, int pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int main(int argc, char *argv[], char *envp[])
{
	char	*cmd1;
	char	*cmd2;
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	int		pid1;
	int		pid2;

	pid1 = 0;
	if (argc != 5)
		write_err("Wrong input format", 1, 1);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	cmd1 = argv[2];
	cmd2 = argv[3];
	if (pipe(pipe_fd) == -1)
		write_err("Error opening Pipe", 1, 1);
	if (check_errors(argv, cmd1, cmd2) == 0)
	{
		pid1 = fork();
		if (pid1 < 0)
			write_err("Error Fork1", 1, 1);
		if (pid1 == 0)	//child process for first command
			child_pid1(infile, cmd1, pipe_fd, envp);
	}
	pid2 = fork();
	if (pid2 < 0)
		write_err("Error Fork2", 1, 1);
	if (pid2 == 0)	//child process for second command
		child_pid2(outfile, cmd2, pipe_fd, envp);
	ft_close(infile, outfile, pipe_fd);
	ft_wait(pid1, pid2);
	if (check_errors(argv, cmd1, cmd2) == 1)
		exit_reason(1);
}
