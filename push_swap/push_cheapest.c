/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:30:51 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/26 13:31:57 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_cheapest(t_stack *stack_b)
{
	int		cost;
	int		cost_current;
	t_stack	*current;
	t_stack	*cheapest;

	cost = INT_MAX;
	current = stack_b;
	while (current)
	{
		cost_current = current->ra + current->rb + current->rra
			+ current->rrb + current->rr + current->rrr;
		if (cost_current < cost)
		{
			cheapest = current;
			cost = cost_current;
		}
		current = current->next;
	}
	return (cheapest);
}

void	set_to_zero(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		current->ra = 0;
		current->rb = 0;
		current->rra = 0;
		current->rrb = 0;
		current->rr = 0;
		current->rrr = 0;
		current = current->next;
	}
}

void	push_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	set_to_zero(*stack_b);
	assign_rotations(stack_a, stack_b);
	correct_rotations(*stack_b);
	correct_rev_rotations(*stack_b);
	cheapest = find_cheapest(*stack_b);
	rotate_push_1(cheapest, stack_a, stack_b);
	rotate_push_2(cheapest, stack_a, stack_b);
	push_a(stack_a, stack_b);
}
