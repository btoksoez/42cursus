/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:08:25 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
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
		c = -(*n);
		*m = 1;
		*d = 1;
	}
	if (*n == 0)
		*d = 1;
	while (c > 0)
	{
		c /= 10;
		*d += 1;
	}
	return (*d);
}

static char	*test_int(void)
{
	char	*s;

	s = (char *)malloc(12);
	if (!s)
		return (NULL);
	ft_strlcpy(s, "-2147483648", 12);
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		d;
	int		m;

	if (n == -2147483648)
		return (test_int());
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
		s[0] = ft_abs(n) + '0';
	return (s);
}
// #include <stdio.h>
// #include <string.h>
// int main(void)
// {

//     char *result = ft_itoa(0);
// 	ft_printf("%s", result);
// 	free(result);

//     return 0;
// }
