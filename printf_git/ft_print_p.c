/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:58:22 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/24 14:19:23 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(const char *format, va_list args)
{
	void	*p;

	p = (void *)va_arg(args, void *);
	ft_print_hex(p);
	return (15);
}
