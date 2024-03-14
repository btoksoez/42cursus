/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:24:04 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;
	char	*new_big;

	i = 0;
	if (!big || !little)
		return (NULL);
	new_big = (char *)big;
	little_len = ft_strlen(((char *)little));
	if (little_len == 0 || big == little)
		return (new_big);
	while (new_big[i] != '\0' && i < len)
	{
		j = 0;
		while ((new_big[i + j] == little[j]) && (little[j] != '\0')
			&& (i + j < len) && (new_big[i + j] != '\0'))
			j++;
		if (j == little_len)
			return (new_big + i);
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// int main(void)
// {
// 	ft_printf("%s", ft_strnstr("", "j", 2));
// }
