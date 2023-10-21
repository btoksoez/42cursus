/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:54:36 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/21 18:02:21 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(const char *format, va_list args)
{
	char	*s;

	if (!format || !args)
		return (0);
	s = va_arg(args, char *);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
