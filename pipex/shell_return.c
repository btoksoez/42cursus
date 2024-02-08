/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:15 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/08 21:29:56 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//returns 0 if command executable, else otherwise

int shell_return(char *cmd)
{
	int	shellpid1;
	int	status;
	int	dev_null;

	shellpid1 = fork();
	if (shellpid1 < 0)
	{
		perror("Shell Fork 1");
		exit(EXIT_FAILURE);
	}
	else if (shellpid1 == 0)	//child process for first command
	{
		dev_null = open("/dev/null", O_RDWR);
		if (dev_null == -1)
		{
            perror("open");
            exit(EXIT_FAILURE);
		}
		if (dup2(dev_null, STDIN_FILENO) == -1)
		{
			perror("Dev null in");
			exit(EXIT_FAILURE);
		}
		if (dup2(dev_null, STDOUT_FILENO) == -1)
		{
			perror("Dev null out");
			exit(EXIT_FAILURE);
		}
		if (dup2(dev_null, STDERR_FILENO) == -1)
		{
			perror("Dev null err");
			exit(EXIT_FAILURE);
		}
		close(dev_null);
		execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd, NULL}, NULL);
		perror("Shell Execve1 failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		int wait_result = waitpid(shellpid1, &status, 0);
        if (wait_result == -1)
		{
            perror("waitpid");
            exit(EXIT_FAILURE);
		}
		return (status);
	}
}

// int main()
// {
//     char *cmd = "grep"; // Example command
//     int exit_code = shell_return(cmd);
//     printf("Exit code of '%s': %d\n", cmd, exit_code);
//     return 0;
// }

