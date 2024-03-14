/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:39:32 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// void printContent(void *content) {
//     ft_printf("Content: %d\n", *(int*)content);
// }

// int main() {
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

//     // Define a function to print the content of each node

//     // Apply the print function to each node's content
//     ft_lstiter(node1, printContent);

//     // Free the memory for the list nodes

//     return 0;
// }
