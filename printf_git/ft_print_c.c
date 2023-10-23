/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:33:16 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/23 17:55:16 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(const char *format, va_list args)
{
	char	c;

	if (!format || !args)
		return (0);
	c = (char)va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}
