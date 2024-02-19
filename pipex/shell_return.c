/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:15 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/19 14:30:02 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	shell_return(char *cmd, char *envp[], t_pipex *pipex)
{
	int	shellpid1;
	int	status;
	int	wait_result;

	shellpid1 = fork();
	if (shellpid1 < 0)
		write_err("Shell Fork 1", 1, 1, NULL);
	else if (shellpid1 == 0)
		child_shell(cmd, envp, pipex);
	else
	{
		wait_result = waitpid(shellpid1, &status, 0);
		if (wait_result == -1)
			write_err("waitpid shell", 1, 1, NULL);
		return (status);
	}
	return (1);
}

void	child_shell(char *cmd, char *envp[], t_pipex *pipex)
{
	int	dev_null;

	dev_null = open("/dev/null", O_RDWR);
	if (dev_null == -1)
	{
		write_err("error open dev_null", 1, 1, pipex);
	}
	if (dup2(dev_null, STDIN_FILENO) == -1)
	{
		write_err("error dup dev_null", 1, 1, pipex);
	}
	if (dup2(dev_null, STDOUT_FILENO) == -1
		|| dup2(dev_null, STDERR_FILENO) == -1)
	{
		write_err("error dup2 dev_null", 1, 1, pipex);
	}
	close(dev_null);
	execve("/bin/sh", (char *[]){"/bin/sh", "-c", cmd, NULL}, envp);
	perror("Shell Execve1 failed");
	exit(EXIT_FAILURE);
}
// int main()
// {
//     char *cmd = "grep 3434"; // Example command
//     int exit_code = shell_return(cmd);
//     printf("Exit code of '%s': %d\n", cmd, exit_code);
//     return 0;
// }
