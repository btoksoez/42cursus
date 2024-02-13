/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:42:07 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/13 14:23:46 by btoksoez         ###   ########.fr       */
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

int		shell_return(char *cmd, char *envp[]);
void	child_shell(char *cmd, char *envp[]);

void	write_err(char *error_message, int new_line, int exit_true);
int		check_errors(char *argv[], char *cmd1, char *cmd2);
int		check_infile(char *argv);
int		check_outfile(char *argv);
int		check_cmd(char *cmd, char *envp[]);
void	exit_reason(int reason);
void	ft_wait(int pid1, int pid2);
#endif
