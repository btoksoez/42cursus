/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:39:51 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>

// void	*ft_memchr(const void *s, int c, size_t n);

// int main() {
//     // Test case 1: Search for 'A' in a string
//     char str1[] = "Hello, World!";
//     int search1 = 'e';
//     size_t n1 = strlen(str1);

//     void *result1 = ft_memchr(str1, search1, n1);
//     if (result1) {
//         ft_printf("Found '%c' at index %ld\n",
// search1, (char *)result1 - str1);
//     } else {
//         ft_printf("'%c' not found in the string.\n", search1);
//     }

//     // Test case 2: Search for 'l' in an empty string
//     char str2[] = "";
//     int search2 = 'l';
//     size_t n2 = 0;

//     void *result2 = ft_memchr(str2, search2, n2);
//     if (result2) {
//         ft_printf("Found '%c' at index %ld\n",
// search2, (char *)result2 - str2);
//     } else {
//         ft_printf("'%c' not found in the string.\n", search2);
//     }

//     // Test case 3: Search for '\0' (null terminator) in a string
//     char str3[] = "Hello\0World!";
//     int search3 = '\0';
//     size_t n3 = strlen(str3) + 1; // Include
// //the null terminator in the search

//     void *result3 = ft_memchr(str3, search3, n3);
//     if (result3) {
//         ft_printf("Found '%c' at index %ld\n",
// search3, (char *)result3 - str3);
//     } else {
//         ft_printf("'%c' not found in the string.\n", search3);
//     }

//     return 0;
// }
