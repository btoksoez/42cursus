/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:02:07 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/18 14:18:06 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_rotations(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;

	if (!stack_b || !stack_a)
		return ;
	current = stack_b;
	while (current)
	{
		current->ra = rotations_a(current, stack_a, stack_b);
		current->rb = rotations_b(current, stack_a, stack_b);
		current->rra = rev_rotations_a(current, stack_a, stack_b);
		current->rrb = rev_rotations_b(current, stack_a, stack_b);
		current = current->next;
	}
}

int rotations_a(t_stack *current, t_stack *stack_a, t_stack *stack_b)
{
	t_stack *element_a;

	element_a = stack_a;
	while (element_a->index < current->index && element_a->next != NULL)
		element_a = element_a -> next;
	if (element_a->next == NULL && element_a->index < current->index)
		return (0);
	if (element_a->position > (ft_stacksize(stack_a) / 2 + 1))
		return (0);
	else
		return (element_a->position - 1);
}

int rev_rotations_a(t_stack *current, t_stack *stack_a, t_stack *stack_b)
{
	t_stack *element_a;

	element_a = stack_a;
	while (element_a->index < current->index && element_a->next != NULL)
		element_a = element_a -> next;
	if (element_a->next == NULL && element_a->index < current->index)
		return (0);
	if (element_a->position > (ft_stacksize(stack_a) / 2 + 1))
		return (ft_stacksize(stack_a) - element_a->position + 1);
	else
		return (0);
}

int	rotations_b(t_stack *current, t_stack *stack_a, t_stack *stack_b)
{
	if (current->position > (ft_stacksize(stack_b) / 2 + 1))
		return (0);
	return (current->position - 1);
}

int	rev_rotations_b(t_stack *current, t_stack *stack_a, t_stack *stack_b)
{
	if (current->position > (ft_stacksize(stack_b) / 2 + 1))
		return (ft_stacksize(stack_b) - current->position + 1);
	else
		return (0);
}
