/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:16:22 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/30 14:18:26 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_stack **stack_a)
{
	int		rotations;
	int		stacksize;
	t_stack	*current;

	current = *stack_a;
	stacksize = ft_stacksize(*stack_a);
	rotations = 0;
	if (current->index > (stacksize / 2 + 1))
	{
		rotations = stacksize - current->index + 1;
		while (rotations--)
			rotate(stack_a, 'a', 0);
	}
	else
	{
		rotations = current->index - 1;
		while (rotations--)
			reverse_rotate(stack_a, 'a', 0);
	}
}
