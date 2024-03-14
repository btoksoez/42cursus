/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:54:23 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = ((char *)s1)[i];
		i++;
	}
	while (*s2)
	{
		res[i] = *s2;
		i++;
		s2++;
	}
	res[i] = '\0';
	return (res);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char *p;
// 	p = NULL;
// 	char *res = ft_strjoin(p, "ccc");
// 	ft_printf("%s", res);
// }
