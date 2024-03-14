/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:09:03 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
// int main() {
//     // Create some test data
//     int data1 = 42;
//     int data2 = 123;
//     int data3 = 789;

//     // Create some list nodes and initialize them
//     t_list *node1 = (t_list *)malloc(sizeof(t_list));
//     t_list *node2 = (t_list *)malloc(sizeof(t_list));
//     t_list *node3 = (t_list *)malloc(sizeof(t_list));

//     node1->content = &data1;
//     node2->content = &data2;
//     node3->content = &data3;

//     // Initialize the next pointers to NULL
//     node1->next = NULL;
//     node2->next = NULL;
//     node3->next = NULL;

//     // Create a head pointer and set it to NULL (empty list)
//     t_list *head = NULL;

//     ft_printf("Initial state: Empty list\n");

//     // Add nodes to the front of the list
//     ft_printf("Adding node1 to the front of the list\n");
//     ft_lstadd_front(&head, node1);

//     ft_printf("Adding node2 to the front of the list\n");
//     ft_lstadd_front(&head, node2);

//     ft_printf("Adding node3 to the front of the list\n");
//     ft_lstadd_front(&head, node3);

//     // Traverse the list and print the content of each node
//     ft_printf("Traversing the list and printing the content:\n");

//     t_list *current = head;
//     while (current) {
//         ft_printf("Content: %d\n", *((int *)current->content));
//         current = current->next;
//     }

//     // Clean up (free memory)
//     free(node1);
//     free(node2);
//     free(node3);

//     return 0;
// }
