/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:30:51 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/25 12:41:06 by btoksoez         ###   ########.fr       */
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

t_stack	*find_cheapest(t_stack *stack_a, t_stack *stack_b)
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

void	rotate_push(t_stack *current, t_stack **stack_a, t_stack **stack_b)
{

	while (current->ra > 0)
	{
		rotate(stack_a);
		current->ra = current->ra - 1;
		ft_printf("ra\n");
	}
	while (current->rb > 0)
	{
		rotate(stack_b);
		current->rb = current->rb - 1;
		ft_printf("rb\n");
	}
	while (current->rra > 0)
	{
		reverse_rotate(stack_a);
		current->rra = current->rra - 1;
		ft_printf("rra\n");
	}
	while (current->rrb > 0)
	{
		reverse_rotate(stack_b);
		current->rrb = current->rrb - 1;
		ft_printf("rrb\n");
	}
	while (current->rr > 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		current->rr = current->rr - 1;
		ft_printf("rr\n");
	}
	while (current->rrr > 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		current->rrr = current->rrr - 1;
		ft_printf("rrr\n");
	}
	push_a(stack_a, stack_b);
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
	cheapest = find_cheapest(*stack_a, *stack_b);
	rotate_push(cheapest, stack_a, stack_b);
}
