/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:21:22 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/26 13:21:29 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	correct_rotations(t_stack *stack_b)
{
	t_stack	*current;

	current = stack_b;
	while (current)
	{
		if (current->ra && current->rb)
		{
			if (current->ra > current->rb)
			{
				current->rr = current->rb;
				current->ra = current->ra - current->rb;
				current->rb = 0;
			}
			else
			{
				current->rr = current->ra;
				current->rb = current->rb - current->ra;
				current->ra = 0;
			}
		}
		current = current->next;
	}
}

void	correct_rev_rotations(t_stack *stack_b)
{
	t_stack	*current;

	current = stack_b;
	while (current)
	{
		if (current->rra && current->rrb)
		{
			if (current->rra > current->rrb)
			{
				current->rrr = current->rrb;
				current->rra = current->rra - current->rrb;
				current->rrb = 0;
			}
			else
			{
				current->rrr = current->rra;
				current->rrb = current->rrb - current->rra;
				current->rra = 0;
			}
		}
		current = current->next;
	}
}
