/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:13:40 by btoksoez          #+#    #+#             */
/*   Updated: 2023/11/07 17:14:30 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
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
// int main(void)
// {
//     int fd;
//     char *result;

//     fd = open("test.txt", O_RDONLY);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     return (0);
// }
