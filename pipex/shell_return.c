/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:15 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/07 14:27:27 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int shell_return(char *cmd, char *envp[])
{
	int	pipe_fd[2]; //fd[1] = write, fd[0] = read
	int	shellpid1;
	int	shellpid2;
	char	exit_code[10];
	int		res;

	if (pipe(pipe_fd) == -1)
	{
		perror("Error opening Shell Pipe");
		exit(EXIT_FAILURE);
	}
	shellpid1 = fork();
	if (shellpid1 < 0)
	{
		perror("Shell Fork 1");
		exit(EXIT_FAILURE);
	}
	else if (shellpid1 == 0)	//child process for first command
	{
		close(pipe_fd[0]); //close read end of pipe
		dup2(pipe_fd[1], STDOUT_FILENO); //reroute stdout to write end of pipe
		close(pipe_fd[1]);
		//execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd, "|", "echo $?", NULL}, envp);
		perror("Shell Execve1 failed");
		exit(EXIT_FAILURE);
	}

	else
	{
		waitpid(shellpid1, NULL, 0);
		close(pipe_fd[1]); //close write end of pipe
		if (read(pipe_fd[0], exit_code, sizeof(exit_code)) < 0)
			return (-1); //error with read
		close(pipe_fd[0]);
		res = ft_atoi(exit_code);
		return (res);
	}
}

int main()
{
    char *cmd = "hello"; // Example command
    int exit_code = shell_return(cmd, NULL);
    printf("Exit code of '%s': %d\n", cmd, exit_code);
    return 0;
}
