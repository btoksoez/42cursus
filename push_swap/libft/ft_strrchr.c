/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:27:05 by btoksoez          #+#    #+#             */
/*   Updated: 2023/11/09 12:31:46 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*s)
	{
		s++;
		i++;
	}
	while (i >= 0)
	{
		if ((char)*s == (char)c)
			return ((char *)s);
		i--;
		s--;
	}
	return (NULL);
}
