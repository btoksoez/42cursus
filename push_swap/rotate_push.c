/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:20:48 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/26 13:20:57 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_push_1(t_stack *current, t_stack **stack_a, t_stack **stack_b)
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
}

void	rotate_push_2(t_stack *current, t_stack **stack_a, t_stack **stack_b)
{
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
}
