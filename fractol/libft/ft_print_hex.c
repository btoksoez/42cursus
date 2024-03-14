/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:46:44 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex_recursive(unsigned long n, int count)
{
	char			c;

	if (n >= 16)
		count += ft_print_hex_recursive((n / 16), count);
	c = "0123456789abcdef"[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_print_hex(void *p)
{
	unsigned long	int_p;
	int				res;

	int_p = (unsigned long)p;
	if (int_p == 0)
	{
		write(1, &"(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	res = 2;
	res += ft_print_hex_recursive(int_p, 0);
	return (res);
}
// #include <stdio.h>
// int main(void)
// {
// 	void *p;
// 	p = (void *)-1;
// 	int n1 = ft_print_hex(p);
// 	write(1, "\n", 1);
// 	int n2 = ft_printf("%p", p);
// 	ft_printf("\nft: %d, pr: %d", n1, n2);
// }
