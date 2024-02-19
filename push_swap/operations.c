/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:01:50 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/12 11:11:19 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char stackname, int both)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*current;

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
	if (both == 0)
		ft_printf("r%c\n", stackname);
	update_position(stack);
}

void	reverse_rotate(t_stack **stack, char stackname, int both)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*current;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	current = first->next;
	while (current->next != NULL)
	{
		last = current;
		current = current->next;
		current->previous = last;
	}
	last = current->previous;
	last->next = NULL;
	first->previous = current;
	current->previous = NULL;
	current->next = first;
	*stack = current;
	if (both == 0)
		ft_printf("rr%c\n", stackname);
	update_position(stack);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
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
	ft_printf("pb\n");
	update_position(stack_b);
	update_position(stack_a);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
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
	ft_printf("pa\n");
	update_position(stack_b);
	update_position(stack_a);
}

void	swap_stack(t_stack **stack, char stackname)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	first->previous = second;
	second->next = first;
	second->previous = NULL;
	*stack = second;
	ft_printf("s%c\n", stackname);
	update_position(stack);
}
