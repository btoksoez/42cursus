/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:13:40 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/26 14:58:28 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char buffer[buffer_size];
	char *res;
	ssize_t bytes_read;
	int		i;
	int		j;

	i = 0;
	while(read(fd, &buffer[i], sizeof(buffer)))
	{
		while (buffer[i])
		{
			printf("%c", buffer[i]);
			i++;
		}
	}
	return (0);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);

    while (line)
	{
		get_next_line(fd);
    }
    close(fd);
    return 0;
}
