/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:53:09 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_lst;
	void	*new_content;

	if (!f || !lst || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// t_list	*ft_lstmap1(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new_lst;
// 	t_list	*new_elem;

// 	if (!lst || !f)
// 		return (NULL);
// 	if (!(new_elem = ft_lstnew(f(lst->content))))
// 	{
// 		ft_lstclear(&lst, del);
// 		return (NULL);
// 	}
// 	new_lst = new_elem;
// 	lst = lst->next;
// 	while (lst)
// 	{
// 		if (!(new_elem = ft_lstnew(f(lst->content))))
// 		{
// 			ft_lstclear(&lst, del);
// 			ft_lstclear(&new_lst, del);
// 			break ;
// 		}
// 		lst = lst->next;
// 		ft_lstadd_back(&new_lst, new_elem);
// 	}
// 	return (new_lst);
// }

// #include <stdio.h>
// // Example transformation function that doubles an integer
// void *doubleInt(void *content) {
//     int *original = (int *)content;
//     int *doubled = (int *)malloc(sizeof(int));
//     *doubled = (*original) * 2;
//     return (void *)doubled;
// }
// // Example content deletion function for integers
// void deleteInt(void *content) {
//     free(content);
// }

// // Function to display a linked list
// void displayList(t_list *list, const char *label) {
//     ft_printf("%s:\n", label);
//     while (list) {
//         int *data = (int *)list->content;
//         ft_printf("Content: %d\n", *data);
//         list = list->next;
//     }
//     ft_printf("\n");
// }

// int main() {
//     // Test case 1: Empty list
//     t_list *empty_list = NULL;
//     t_list *result1 = ft_lstmap(empty_list, doubleInt, deleteInt);
//     t_list *result1_other = ft_lstmap1(empty_list, doubleInt, deleteInt);

//     ft_printf("Test Case 1:\n");
//     displayList(result1, "Your ft_lstmap result");
//     displayList(result1_other, "Other solution result");

//     // Test case 2: List with one node
//     int data = 5;
//     t_list *node = ft_lstnew(&data);
//     t_list *result2 = ft_lstmap(node, doubleInt, deleteInt);
//     t_list *result2_other = ft_lstmap1(node, doubleInt, deleteInt);

//     ft_printf("Test Case 2:\n");
//     displayList(result2, "Your ft_lstmap result");
//     displayList(result2_other, "Other solution result");

//     // Test case 3: List with multiple nodes
//     int data1 = 1;
//     int data2 = 2;
//     int data3 = 3;
//     t_list *list = ft_lstnew(&data1);
//     ft_lstadd_back(&list, ft_lstnew(&data2));
//     ft_lstadd_back(&list, ft_lstnew(&data3));
//     t_list *result3 = ft_lstmap(list, doubleInt, deleteInt);
//     t_list *result3_other = ft_lstmap1(list, doubleInt, deleteInt);

//     ft_printf("Test Case 3:\n");
//     displayList(result3, "Your ft_lstmap result");
//     displayList(result3_other, "Other solution result");

//     // Free the memory for the result lists
//     ft_lstclear(&result1, deleteInt);
//     ft_lstclear(&result2, deleteInt);
//     ft_lstclear(&result3, deleteInt);

//     ft_lstclear(&result1_other, deleteInt);
//     ft_lstclear(&result2_other, deleteInt);
//     ft_lstclear(&result3_other, deleteInt);

//     return 0;
// }
