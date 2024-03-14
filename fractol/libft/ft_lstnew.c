/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:55:22 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
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
//         ft_printf("Content: %d\n", *((int *)node->content));
// 		ft_printf("Next: %p\n", ((void *)node->next));
//         free(node);
//     } else {
//         ft_printf("Failed to create a node.\n");
//     }

//     return 0;
// }
