/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:15 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/07 15:12:25 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int shell_return(char *cmd, char *envp[])
{
	int	shellpid1;
	int	status;

	shellpid1 = fork();
	if (shellpid1 < 0)
	{
		perror("Shell Fork 1");
		exit(EXIT_FAILURE);
	}
	else if (shellpid1 == 0)	//child process for first command
	{
		execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd, NULL}, envp);
		perror("Shell Execve1 failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(shellpid1, &status, 0);
		return (status);
	}
}

int main()
{
    char *cmd = "cat"; // Example command
    int exit_code = shell_return(cmd, NULL);
    printf("Exit code of '%s': %d\n", cmd, exit_code);
    return 0;
}


//check if it returns 0 for all valid commands, and else otherwise
