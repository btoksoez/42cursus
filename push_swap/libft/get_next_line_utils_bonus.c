/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:54:52 by btoksoez          #+#    #+#             */
/*   Updated: 2023/12/27 09:40:47 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_next(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_next(char *line, char *buffer)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc(ft_strlen_next(line) + ft_strlen_next(buffer) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		res[i] = ((char *)line)[i];
		i++;
	}
	if (line)
		free(line);
	j = 0;
	while (buffer[j])
	{
		res[i++] = buffer[j];
		if (buffer[j++] == '\n')
			break ;
	}
	res[i] = '\0';
	return (res);
}
