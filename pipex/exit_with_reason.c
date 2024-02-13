/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_reason.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:45:50 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/13 12:47:46 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_reason(int reason)
{
	if (reason == 0)
		exit(0);
	if (reason == 1)
		exit(1);
	if (reason == 2)
		exit(2);
	if (reason == 127)
		exit(127);
}
