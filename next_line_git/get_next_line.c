/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:13:40 by btoksoez          #+#    #+#             */
/*   Updated: 2023/11/05 18:26:15 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
}

void	shift_buffer(char *buffer)
{
	char	*new_start;

	new_start = (ft_strchr(buffer, '\n') + 1);
	if (new_start[0] == '\0')
		clean_buffer(buffer);
	else
		ft_strlcpy(buffer, (new_start), ft_strlen(new_start));
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
		if (ft_strchr(buffer, '\n'))
		{
			shift_buffer(buffer);
			break ;
		}
		else
			clean_buffer(buffer);
	}
	return (line);
}

int main(void)
{
    int fd;
    char *result;

    fd = open("test.txt", O_RDONLY);
    result = get_next_line(fd);
    printf("final: %s\n", result);
    free(result);
    result = get_next_line(fd);
    printf("final: %s\n", result);
    free(result);
    result = get_next_line(fd);
    printf("final: %s\n", result);
    free(result);
    result = get_next_line(fd);
    printf("final: %s\n", result);
    free(result);
    result = get_next_line(fd);
    printf("final: %s\n", result);
    free(result);
    result = get_next_line(fd);
    printf("final: %s\n", result);
    free(result);
    return (0);
}
