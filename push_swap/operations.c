/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:01:50 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/10 16:05:24 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(FILE *commands, t_stack **stack, char name)
{
	t_stack *first;
	t_stack *second;
	t_stack *current;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	current = first->next;
	first->next = NULL;
	second->previous = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->previous = current;
	*stack = second;
	fprintf(commands, "r%c\n", name);
}

void reverse_rotate(FILE *commands, t_stack **stack, char name)
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
	fprintf(commands, "rr%c\n", name);
}

void push_b(FILE *commands, t_stack **stack_a, t_stack **stack_b, t_info *info)
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
	update_info(stack_a, stack_b, info);
	fprintf(commands, "pb\n");	//print pb
}

// void print_stack(t_stack *stack, char name)
// {
//     printf("Stack %c: ", name);
//     while (stack)
//     {
//         printf("(%d, %d) ", stack->value, stack->position);
//         stack = stack->next;
//     }
//     printf("\n");
// }

// int main()
// {
//     // Create a stack with some values
//     char *arr[] = {"1", "2", "3", "4", "5", NULL};
//     t_stack *stack_a = stackcreate(arr);

//     // Print the initial state of the stack
//     print_stack(stack_a, 'A');

//     // Open a commands file for writing
//     FILE *commands = fopen("commands.txt", "w");

//     // Test rotate and reverse_rotate functions
//     rotate(commands, &stack_a, 'A');
//     print_stack(stack_a, 'A');
//     update_position(&stack_a);
//     print_stack(stack_a, 'A');

//     reverse_rotate(commands, &stack_a, 'A');
//     print_stack(stack_a, 'A');
//     update_position(&stack_a);
//     print_stack(stack_a, 'A');

//     // Add a new element to the stack
//     t_stack *new_element = ft_stacknew(6);
//     ft_stackadd_back(&stack_a, new_element);
//     print_stack(stack_a, 'A');

//     // Test rotate and update position again after adding a new element
//     rotate(commands, &stack_a, 'A');
//     print_stack(stack_a, 'A');
//     update_position(&stack_a);
//     print_stack(stack_a, 'A');

//     // Close the commands file
//     fclose(commands);

//     return 0;
// }
