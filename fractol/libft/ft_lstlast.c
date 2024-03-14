/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:00:27 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*rtn;

	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	rtn = lst;
	return (rtn);
}
// int main(void)
// {
//     // Create an empty list
//     t_list *emptyList = NULL;
//     ft_printf("Empty List:\n");
//     t_list *lastNode = ft_lstlast(emptyList);
//     if (lastNode == NULL) {
//         ft_printf("List is empty.\n");
//     }

//     // Create a list with nodes
//     int data1 = 1;
//     int data2 = 2;
//     int data3 = 3;

//     t_list *node1 = ft_lstnew(&data1);
//     t_list *node2 = ft_lstnew(&data2);
//     t_list *node3 = ft_lstnew(&data3);

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     ft_printf("\nList with Nodes:\n");
//     lastNode = ft_lstlast(node1);
//     if (lastNode != NULL) {
//         ft_printf("Last Node Content: %d\n", *((int *)(lastNode->content)));
//     }

//     // Free the memory for the list nodes
// 	free(node1);
// 	free(node2);
// 	free(node3);

//     return 0;
// }
