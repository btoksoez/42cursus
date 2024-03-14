/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:07:56 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
			count++;
		while (*s && (!(*s == c)))
			s++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && (!(*s == c)))
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_mystrdup(const char *s, int len)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_free_split(char **split)
{
	size_t	i;

	i = 0;
	if (!split)
		return (NULL);
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			res[i++] = ft_mystrdup(s, word_len(s, c));
			if (!res[i - 1])
				return (ft_free_split(res));
		}
		while (*s && (!(*s == c)))
			s++;
	}
	res[i] = NULL;
	return (res);
}
// #include <stdio.h>
// int main(void)
// {
// 	char *s = NULL;
// 	char c = 'c';
// 	char **res = ft_split(s, c);
// 	if (!res)
// 	{
// 		ft_printf("null");
// 	 	return (0);
// 	}
// 	while (*res)
// 	{
// 		ft_printf("%s\n", *res);
// 		res++;
// 	}
// 	ft_printf("%s", *res);
// }
