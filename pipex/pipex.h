/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:42:07 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/19 14:54:35 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include <errno.h>

typedef struct s_pipex
{
	int	infile;
	int	outfile;
	int	pipe_fd[2];
	int	dev_null;
}	t_pipex;

int		shell_return(char *cmd, char *envp[], t_pipex *pipex);
void	child_shell(char *cmd, char *envp[], t_pipex *pipex);

void	write_err(char *message, int new_line, int exit_code, t_pipex *pipex);

int		check_infile(char *argv);
int		check_outfile(char *argv);
int		check_cmd(char *cmd, char *envp[], t_pipex *pipex);

void	ft_close(t_pipex *pipex);
void	ft_wait(int pid1, int pid2);
#endif
