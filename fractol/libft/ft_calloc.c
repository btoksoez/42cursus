/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:05:53 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (size * nmemb > 2147483647)
		return (NULL);
	if (!nmemb || !size)
		return (malloc(0));
	res = malloc(size * nmemb);
	if (!res)
		return (NULL);
	ft_bzero(res, (size * nmemb));
	return (res);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h> // for INT_MAX

// int main() {
//     size_t nmemb = (size_t)INT_MAX;
//     size_t size = sizeof(int);

//     int *arr = (int *)ft_calloc(nmemb, size);

//     if (arr == NULL) {
//         ft_printf("Memory allocation failed due to integer overflow.\n");
//         return 1;
//     }

//     // Successfully allocated memory for a large array.
//     // You can work with this memory here.

//     // Don't forget to free the allocated memory when you're done with it.
//     free(arr);

//     return 0;
// }
