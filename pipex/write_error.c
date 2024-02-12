/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:49:36 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/12 15:11:09 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_err(char *error_message, int ex, int new_line)
{
	write(STDERR_FILENO, error_message, ft_strlen(error_message));
	if (new_line == 1)
		write(STDERR_FILENO, "\n", 1);
	if (ex == 1)
		exit(EXIT_FAILURE);
}
