/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:07:56 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/11 14:18:02 by btoksoez         ###   ########.fr       */
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
	if (*s == c)
		count -= 1;
	while (*s)
	{
		if (is_delimiter(*s, c))
			count++;
		s++;
	}
	if (is_delimiter(*(s - 1), c))
		count -= 1;
	return (count + 1);
}
// char	**ft_split(char const *s, char c)
// {
// }

int main(void)
{
	printf("%d", count_words("foooffffooofoof", 'f'));
}
