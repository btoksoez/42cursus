/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:20:48 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/30 14:23:43 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_push_1(t_stack *current, t_stack **stack_a, t_stack **stack_b)
{
	while (current->ra > 0)
	{
		rotate(stack_a, 'a', 0);
		current->ra = current->ra - 1;
	}
	while (current->rb > 0)
	{
		rotate(stack_b, 'b', 0);
		current->rb = current->rb - 1;
	}
	while (current->rra > 0)
	{
		reverse_rotate(stack_a, 'a', 0);
		current->rra = current->rra - 1;
	}
}

void	rotate_push_2(t_stack *current, t_stack **stack_a, t_stack **stack_b)
{
	while (current->rrb > 0)
	{
		reverse_rotate(stack_b, 'b', 0);
		current->rrb = current->rrb - 1;
	}
	while (current->rr > 0)
	{
		rotate(stack_a, 'a', 1);
		rotate(stack_b, 'b', 1);
		ft_printf("rr\n");
		current->rr = current->rr - 1;
	}
	while (current->rrr > 0)
	{
		reverse_rotate(stack_a, 'a', 1);
		reverse_rotate(stack_b, 'b', 1);
		ft_printf("rrr\n");
		current->rrr = current->rrr - 1;
	}
}
