/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:33:27 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/05 13:48:21 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	res = (char *)malloc((i + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
// #include <stdio.h>
// #include <string.h>
// int main() {
//     const char *original = "Hello, World!";
//     char *duplicate = ft_strdup(original);

//     if (duplicate == NULL) {
//         printf("Memory allocation for duplicate failed.\n");
//         return 1;
//     }

//     // Check if the duplicate is equal to the original
//     if (strcmp(duplicate, original) == 0) {
//         printf("Original and duplicate strings
//are the same: %s\n", duplicate);
//     } else {
//         printf("Original and duplicate strings are different.\n");
//     }

//     // Don't forget to free the allocated mem
//ory when you're done with it.
//     free(duplicate);

//     return 0;
// }
