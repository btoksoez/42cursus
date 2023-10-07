/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:08:08 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/07 17:18:04 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	ft_is_in(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (!*s1)
		return (NULL);
	if (!*set)
		return (s1);
	while (ft_is_in(*s1, set))
		s1++;
	while(ft_is_in(s1[ft_strlen(s1) - i], *set)

}
