/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:13:40 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/25 13:47:01 by btoksoez         ###   ########.fr       */
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
		if (buffer[i] == '\n')
		{
			res = (char *)malloc(i + 1);
			if (res)
			{
				j = 0;
				while (j++ <= i)
					res[j] = buffer[j];
				res[i + 1] = '\0';
			}
		}
		i++;
	}
	return (res);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

    while ((line = get_next_line(fd)))
	{
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
