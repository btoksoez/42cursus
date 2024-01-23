/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:01:50 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/23 09:42:53 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	t_stack *current;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	current = first->next;
	second->previous = NULL;
	while (current->next != NULL)
		current = current->next;
	first->next = NULL;
	current->next = first;
	first->previous = current;
	*stack = second;
}

void reverse_rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;
	t_stack *current;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	current = first->next;
	while (current->next != NULL)
		current = current->next;
	last = current->previous;
	last->next = NULL;
	first->previous = current;
	current->previous = NULL;
	current->next = first;
	*stack = current;
}

void push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a1;
	t_stack	*a2;
	t_stack	*b1;

	if (!stack_a || !(*stack_a) || !stack_b)
		return ;
	a1 = *stack_a;
	b1 = *stack_b;
	a2 = a1->next;
	if (b1 != NULL)
		b1->previous = a1;
	if (a2 != NULL)
		a2->previous = NULL;
	a1->next = b1;
	a1->previous = NULL;
	*stack_a = a2;
	*stack_b = a1;
	printf("pb\n");	//print pb
}

void push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b1;
	t_stack	*b2;
	t_stack	*a1;

	if (!stack_a || !(*stack_b) || !stack_b)
		return ;
	a1 = *stack_a;
	b1 = *stack_b;
	b2 = b1->next;
	if (a1 != NULL)
		a1->previous = b1;
	if (b2 != NULL)
		b2->previous = NULL;
	b1->next = a1;
	b1->previous = NULL;
	*stack_a = b1;
	*stack_b = b2;
	printf("pa\n");
}


// int main()
// {
//     // Create a stack with some values
//     char *arr[] = {"1", "2", "3", "4", "5", NULL};
//     t_stack *stack_a = stackcreate(arr);
//     t_stack *stack_b = stackcreate(arr);

//     // Print the initial state of the stack
//     print_stack(stack_a, 'A');
//     print_stack(stack_b, 'B');

//     // Open a commands file for writing

//     // Test rotate and reverse_rotate functions
//     rotate(&stack_a);
//     print_stack(stack_a, 'A');
//     update_position(&stack_a);
//     print_stack(stack_a, 'A');

//     reverse_rotate(&stack_a);
//     print_stack(stack_a, 'A');
//     update_position(&stack_a);
//     print_stack(stack_a, 'A');

//     // Add a new element to the stack
//     t_stack *new_element = ft_stacknew(6);
//     ft_stackadd_back(&stack_a, new_element);
//     print_stack(stack_a, 'A');

//     // Test rotate and update position again after adding a new element
//     push_a(&stack_a, &stack_b);
//     print_stack(stack_a, 'A');
//     print_stack(stack_b, 'B');
//     update_position(&stack_a);
//     print_stack(stack_a, 'A');

//     // Close the commands fil

//     return 0;
// }
