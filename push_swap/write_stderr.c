/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stderr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:05:08 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/29 09:10:40 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    write_stderror(void) 
{
    const char *error_message; 
    
    error_message = "Error\n";
    write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
    return ;
}
