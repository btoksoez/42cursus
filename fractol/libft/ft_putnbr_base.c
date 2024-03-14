/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:43:29 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(long n, char *s)
{
	char	c;
	int		count;
	int		base_len;

	if (!s)
		return (0);
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	base_len = ft_strlen(s);
	if (n >= base_len)
		count += ft_putnbr_base(n / base_len, s);
	c = s[n % base_len];
	write(1, &c, 1);
	count++;
	return (count);
}
// #include <stdio.h>
// int main(void)
// {
// 	ft_printf("\n\n%d",ft_putnbr_base(15, "0123456789abcdef"));
// }
