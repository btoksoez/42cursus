/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:08:08 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/12 09:45:03 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_is_in(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_getstart(const char *s1, const char *set)
{
	int	start;

	start = 0;
	while (ft_is_in(s1[start], (char *)set) && s1[start])
		start++;
	return (start);
}

static int	ft_getend(const char *s1, const char *set)
{
	int	end;

	end = ft_strlen(s1) - 1;
	while (ft_is_in(s1[end], (char *)set) && s1[end])
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		start;
	int		end;

	if (!*s1)
		return (NULL);
	if (!*set)
		return ((char *)s1);
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	res = (char *)malloc(end - start + 2);
	if (!res)
		return (NULL);
	res[end - start + 1] = '\0';
	i = 0;
	while (end >= start)
	{
		res[i] = s1[start];
		start++;
		i++;
	}
	return (res);
}
// int	main(void)
// {
// 	char *res = ft_strtrim("fef", "fef");
// 	printf("%s", res);
// }
