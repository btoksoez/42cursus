/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:55:22 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/17 12:03:32 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (NULL);
	rtn->content = content;
	rtn->next = NULL;
	return (rtn);
}
// int main() {
//     int data = 42;
//     t_list *node = ft_lstnew(&data);

//     if (node) {
//         printf("Content: %d\n", *((int *)node->content));
// 		printf("Next: %p\n", ((void *)node->next));
//         free(node);
//     } else {
//         printf("Failed to create a node.\n");
//     }

//     return 0;
// }
