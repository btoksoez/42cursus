/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:11:07 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == '\0' || c == 0)
		return ((str));
	return (NULL);
}
// #include <stdio.h>

// char	*ft_strchr(const char *s, int c);

// int main() {
//     char str[] = "Hello, World!";
//     int search1 = 'o';
//     int search2 = '\0';

//     char *result1 = ft_strchr(str, search1);
//     if (result1) {
//         ft_printf("Found '%c' at position %ld\n", search1, result1 - str);
//     } else {
//         ft_printf("'%c' not found in the string.\n", search1);
//     }

//     char *result2 = ft_strchr(str, search2);
//     if (result2) {
//         ft_printf("Found '%c' at position %ld\n", search2, result2 - str);
//     } else {
//         ft_printf("'%c' not found in the string.\n", search2);
//     }

//     return 0;
// }
