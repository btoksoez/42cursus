/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:02:07 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/17 13:04:30 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_rotations(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;

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
    
}
