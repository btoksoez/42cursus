/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:41:24 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/08 17:41:35 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include "pipex.h"



int main(int argc, char *argv[], char *envp[])
{

	//parsing
	char *cmd1;
	char *cmd2;
	int	infile;
	int	outfile;

	if (argc != 5)
	{
		perror("Wrong input format");
		exit(EXIT_FAILURE);
	}

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	cmd1 = argv[2];
	cmd2 = argv[3];
	if (infile == -1 || outfile == -1)
	{
		perror("Error opening files");
		exit(EXIT_FAILURE);
	}


	int	pipe_fd[2]; //fd[1] = write, fd[0] = read
	int	pid1;
	int	pid2;

	if (pipe(pipe_fd) == -1)
	{
		perror("Error opening Pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("Fork 1");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)	//child process for first command
	{
		if (shell_return(cmd1) != 0)
		{
			fprintf(stderr, "command not found: %s\n", cmd1);
			exit(127);
		}
		else
			printf("Status returned: %d\n", shell_return(cmd1));
		dup2(infile, STDIN_FILENO);
		close(infile);
		close(pipe_fd[0]); //close read end of pipe
		dup2(pipe_fd[1], STDOUT_FILENO); //reroute stdout to write end of pipe
		close(pipe_fd[1]);
		execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd1, NULL}, envp);
		perror("Execve1 failed");
		exit(EXIT_FAILURE);
	}

	pid2 = fork();
	if (pid2 < 0)
	{
		perror("Fork 2");
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)	//child process for second command
	{
		if (shell_return(cmd2) != 0)
		{
			fprintf(stderr, "command not found: %s\n", cmd2);
			exit(127);
		}
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		close(pipe_fd[1]); //close write end of pipe
		dup2(pipe_fd[0], STDIN_FILENO); //reroute stdin to read end of pipe
		close(pipe_fd[0]);
		execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd2, NULL}, envp);
		perror("Execve2 failed");
		exit(EXIT_FAILURE);
	}
	close(infile);
	close(outfile);
	close(pipe_fd[0]);	//close for parent process
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);

}


//Questions:
//check if valid command?
	//check with shell_return what exit signal shell has for that command
//check if file ?
//what else need to check
//check exit codes
//check evalsheet
//norminette + sort functionsg





