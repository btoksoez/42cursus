/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:43:29 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/21 17:47:38 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_putnbr_hex(int n, int s)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "80000000", 8);
		return (8);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, s);
	if (s)
		c = "0123456789abcdef"[n % 16];
	else
		c = "0123456789ABCDEF"[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}
// #include <stdio.h>
// int main(void)
// {
// 	printf("\n\n%d",ft_putnbr_hex(2183648, 1));
// }
