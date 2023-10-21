/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:07:56 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/18 18:27:54 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delimiter(char c, char s)
{
	if (c == s)
		return (1);
	return (0);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && is_delimiter(*s, c))
			s++;
		if (*s)
			count++;
		while (*s && (!is_delimiter(*s, c)))
			s++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && (!is_delimiter(*s, c)))
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

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < count_words(s, c))
	{
		while (*s)
		{
			while (*s && is_delimiter(*s, c))
				s++;
			if (*s)
			{
				res[i] = ft_mystrdup(s, word_len(s, c));
				i++;
			}
			while (*s && (!is_delimiter(*s, c)))
				s++;
		}
	}
	res[i] = NULL;
	return (res);
}
// #include <stdio.h>
// int main(void)
// {
// 	char *s = "helloocoeoeoeoc";
// 	char c = 'c';
// 	char **res = ft_split(s, c);
// 	while (*res)
// 	{
// 		printf("%s\n", *res);
// 		res++;
// 	}
// 	printf("%s", *res);
// }
