/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:08:25 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/12 12:25:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	check_n(int *d, int *m, int *n)
{
	int	c;

	*d = 0;
	c = *n;
	*m = 0;
	if (*n < 0)
	{
		c = -*n;
		*m = 1;
		*d = 1;
	}
	while (c > 0)
	{
		c /= 10;
		*d += 1;
	}
	return (*d);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		d;
	int		m;

	if (n == -2147483648)
	{
		s = "-2147483648\n";
		return (s);
	}
	d = check_n(&d, &m, &n);
	s = (char *)malloc((d + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[d--] = '\0';
	while (d > 0)
	{
		s[d--] = ft_abs(n) % 10 + '0';
		n /= 10;
	}
	if (m)
		s[0] = '-';
	else
		s[0] = n + '0';
	return (s);
}
// int	main(void)
// {
// 	printf("%s, %s, %s, %lu, %zu", ft_itoa(0), ft_itoa(54),
//ft_itoa(-5545), sizeof(ft_itoa(123)), ft_strlen(ft_itoa(123)));
// }
