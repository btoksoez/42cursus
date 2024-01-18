/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:30:51 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/18 14:31:29 by btoksoez         ###   ########.fr       */
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

void	rotate_push(t_stack *current, t_stack *stack_a, t_stack *stack_b)
{
	while (current->ra > 0)
	{
		rotate(&stack_a);
		current->ra = current->ra - 1;
		printf("ra\n");
	}
	while (current->rb > 0)
	{
		rotate(&stack_b);
		current->rb = current->rb - 1;
		printf("rb\n");
	}
	while (current->rra > 0)
	{
		reverse_rotate(&stack_a);
		current->rra = current->rra - 1;
		printf("rra\n");
	}
	while (current->rrb > 0)
	{
		reverse_rotate(&stack_b);
		current->rrb = current->rrb - 1;
		printf("rrb\n");
	}
	while (current->rr > 0)
	{
		rotate(&stack_a);
		rotate(&stack_b);
		current->rr = current->rr - 1;
		printf("rr\n");
	}
	while (current->rrr > 0)
	{
		reverse_rotate(&stack_a);
		reverse_rotate(&stack_b);
		current->rrr = current->rrr - 1;
		printf("rrr\n");
	}
	push_a(&stack_a, &stack_b);
	update_position(&stack_a);
	update_position(&stack_b);
}


void	push_cheapest(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	t_stack	*cheapest;
	t_stack	*current; //just for print test

	current = stack_b; //just for print test

	assign_rotations(stack_a, stack_b);
	correct_rotations(stack_b);

	//print test
	while (current) {
		printf("Value: %d, Index: %d, RA: %d, RB: %d, RRA: %d, RRB: %d, RR: %d, RRR: %d\n",
			current->value, current->index, current->ra, current->rb, current->rra, current->rrb, current->rr, current->rrr);
		current = current->next;
	}
	//print test over

	cheapest = find_cheapest(stack_a, stack_b);
	printf("Cheapest Element: %d\n", cheapest->value);
	rotate_push(cheapest, stack_a, stack_b);

	//print test
	current = stack_b;
	while (current) {
		printf("Value: %d, Index: %d, RA: %d, RB: %d, RRA: %d, RRB: %d, RR: %d, RRR: %d\n",
			current->value, current->index, current->ra, current->rb, current->rra, current->rrb, current->rr, current->rrr);
		current = current->next;
	}
	//print test over
	//update_info(&stack_a, &stack_b, info);
}
