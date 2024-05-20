/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:13:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/17 14:29:51 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i++] = 0;
	}
}

int	shift_buffer(char *buffer)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (buffer[i])
	{
		if (found == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			found = 1;
		buffer[i++] = '\0';
	}
	return (found);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (BUFFER_SIZE < 1)
	{
		clean_buffer(buffer);
		return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (shift_buffer(buffer))
			break ;
	}
	return (line);
}
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		printf("(null) EOF");
	close(fd);
}
