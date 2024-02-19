/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:52:16 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/12 11:12:17 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	head_min(t_stack **stack_a)
{
	reverse_rotate(stack_a, 'a', 0);
	swap_stack(stack_a, 'a');
}

void	head_max(t_stack **stack_a, t_stack *head, t_stack *min)
{
	if (head->next == min)
		rotate(stack_a, 'a', 0);
	else
	{
		swap_stack(stack_a, 'a');
		reverse_rotate(stack_a, 'a', 0);
	}
}

void	sort_small(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*min;
	t_stack	*max;

	if (!stack_a)
		return ;
	head = *stack_a;
	min = min_element(*stack_a);
	max = max_element(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (head == min)
		head_min(stack_a);
	else if (head == max)
		head_max(stack_a, head, min);
	else
	{
		if (head->next == min)
			swap_stack(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a', 0);
	}
}
