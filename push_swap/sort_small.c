/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:52:16 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/30 14:43:59 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a)
		return ;
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first < second && second < third)
	{
		ft_printf("hello");
		return ;
	}
	if (first > second && third > second && first > third)
		rotate(stack_a, 'a', 0);
	else if (first > second)
	{
		swap_stack(stack_a, 'a');
		if (second > third)
			reverse_rotate(stack_a, 'a', 0);
	}
	else
	{
		reverse_rotate(stack_a, 'a', 0);
		if (first < third)
			swap_stack(stack_a, 'a');
	}
}
