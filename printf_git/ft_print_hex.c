/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:46:44 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/21 18:02:21 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex_recursive(void *p)
{
	char		c;
	uintptr_t	int_p;

	int_p = (uintptr_t)p;
	if (int_p >= 16)
		ft_print_hex_recursive((void *)(int_p / 16));
	c = "0123456789abcdef"[int_p % 16];
	write(1, &c, 1);
}

void	ft_print_hex(void *p)
{
	write (1, "0x", 2);
	ft_print_hex_recursive(p);
}
// #include <stdio.h>

// int main(void)
// {
// 	void *p;
// 	char c = 'c';

// 	p = &c;
// 	ft_print_hex(p);
// 	write(1, "\n", 1);
// 	printf("%p", p);
// }
