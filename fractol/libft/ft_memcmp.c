/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:12:03 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// int main() {
//     // Test case 1: Compare two equal strings
//     char str1[] = "Hello,";
//     char str2[] = "Hello, Wor";
//     size_t n1 = strlen(str2);

//     int result1 = ft_memcmp(str1, str2, n1);
//     int stdResult1 = memcmp(str1, str2, n1);

//     if (result1 == stdResult1) {
//         ft_printf("Test case 1 passed: Result is %d\n", result1);
//     } else {
//         ft_printf("Test case 1 failed: Result is %d,
//expected %d\n", result1, stdResult1);
//     }

//     // Test case 2: Compare two different strings
//     char str3[] = "Hello, OpenAI!";
//     char str4[] = "Hello, World!";
//     size_t n2 = strlen(str3);

//     int result2 = ft_memcmp(str3, str4, n2);
//     int stdResult2 = memcmp(str3, str4, n2);

//     if (result2 == stdResult2) {
//         ft_printf("Test case 2 passed: Result is %d\n", result2);
//     } else {
//         ft_printf("Test case 2 failed: Result is %d,
//expected %d\n", result2, stdResult2);
//     }

//     // Test case 3: Compare a portion of a string
//     char str5[] = "Hello, World!";
//     char str6[] = "Hello, OpenAI!";
//     size_t n3 = 7;

//     int result3 = ft_memcmp(str5, str6, n3);
//     int stdResult3 = memcmp(str5, str6, n3);

//     if (result3 == stdResult3) {
//         ft_printf("Test case 3 passed: Result is %d\n", result3);
//     } else {
//         ft_printf("Test case 3 failed: Result is %d,
//expected %d\n", result3, stdResult3);
//     }

//     // Test case 4: Compare two empty strings
//     char str7[] = "";
//     char str8[] = "";
//     size_t n4 = 0;

//     int result4 = ft_memcmp(str7, str8, n4);
//     int stdResult4 = memcmp(str7, str8, n4);

//     if (result4 == stdResult4) {
//         ft_printf("Test case 4 passed: Result is %d\n", result4);
//     } else {
//         ft_printf("Test case 4 failed: Result is %d,
//expected %d\n", result4, stdResult4);
//     }

//     // Test case 5: Compare strings with null characters
//     char str9[] = "Hello\0World!";
//     char str10[] = "Hello, OpenAI!";
//     size_t n5 = strlen(str9);

//     int result5 = ft_memcmp(str9, str10, n5);
//     int stdResult5 = memcmp(str9, str10, n5);

//     if (result5 == stdResult5) {
//         ft_printf("Test case 5 passed: Result is %d\n", result5);
//     } else {
//         ft_printf("Test case 5 failed: Result is %d,
//expected %d\n", result5, stdResult5);
//     }

//     return 0;
// }
