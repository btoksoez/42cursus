/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:41:24 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/12 17:02:26 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		write_err("Wrong input format", 1);
		exit(EXIT_FAILURE);
	}

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	cmd1 = argv[2];
	cmd2 = argv[3];
	check_errors(argv, infile, outfile);
	check_cmds(cmd1, cmd2);

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
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		close(pipe_fd[1]); //close write end of pipe
		dup2(pipe_fd[0], STDIN_FILENO); //reroute stdin to read end of pipe
		close(pipe_fd[0]);
		execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd2, NULL}, envp);
		if (errno == ENOENT)
			exit(127);
		perror("Execve2 failed");
		exit(EXIT_FAILURE);
	}
	close(infile);
	close(outfile);
	close(pipe_fd[0]);	//close for parent process
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	// int status;
	// waitpid(pid1, &status, 0);
	// if (WIFEXITED(status)) {
	// 	printf("%d", WEXITSTATUS(status)); // Return exit code of the command
	// } else {
	// 	// Command was terminated by a signal
	// 	printf("%d", 128 + WTERMSIG(status));
	// }
	return (0);
}


//Questions:
//finish checkc mds
//check for file permissions/ file doesn't exist
//check evalsheet
//norminette + sort functions





