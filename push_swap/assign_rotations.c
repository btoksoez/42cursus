/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:02:07 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/26 13:29:27 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_rotations(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*element_a;
	int		stacksize_a;
	int		stacksize_b;

	if (!stack_b || !stack_a)
		return ;
	current = *stack_b;
	stacksize_a = ft_stacksize(*stack_a);
	stacksize_b = ft_stacksize(*stack_b);
	while (current)
	{
		element_a = find_smallest_greater(*stack_a, current->index);
		rotations_a(current, element_a, stacksize_a);
		rotations_b(current, stacksize_b);
		current = current->next;
	}
}

t_stack	*find_smallest_greater(t_stack *stack_a, int index_b)
{
	t_stack	*current;
	t_stack	*element_a;

	current = stack_a;
	element_a = NULL;
	while (current != NULL)
	{
		if (current->index > index_b)
			if (element_a == NULL || current->index < element_a->index)
				element_a = current;
		current = current->next;
	}
	if (element_a == NULL)
		element_a = min_element(stack_a);
	return (element_a);
}

void	rotations_a(t_stack *current, t_stack *element_a, int stacksize)
{
	if (element_a->position > (stacksize / 2 + 1))
		current->rra = stacksize - element_a->position + 1;
	else
		current->ra = element_a->position - 1;
}

void	rotations_b(t_stack *current, int stacksize)
{
	if (current->position > (stacksize / 2 + 1))
		current->rrb = stacksize - current->position + 1;
	else
		current->rb = current->position - 1;
}
