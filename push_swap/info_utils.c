/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:03:09 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/10 15:24:25 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_position(t_stack **stack)
{
	t_stack *current;
	int		i;

	if (!stack)
		return;
	current = *stack;
	i = 1;
	while (current)
	{
		current->position = i;
		current = current->next;
		i++;
	}
}

void	update_info(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	t_stack	*current;
	int		i;

	if (!info || !stack_a || !stack_b)
		return ;
	update_position(stack_a);
	update_position(stack_b);
	info->amax = max_element(*stack_a);
	info->amin = min_element(*stack_a);
	info->bmax = max_element(*stack_b);
	info->bmin = min_element(*stack_b);
}

t_info *init_info(t_stack **stack_a, t_stack **stack_b)
{
	t_info	*info;
	t_stack	*current;
	int		i;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	update_position(stack_a);
	update_position(stack_b);
	info->amax = max_element(*stack_a);
	info->amin = min_element(*stack_a);
	info->bmax = max_element(*stack_b);
	info->bmin = min_element(*stack_b);
	info->mincost = INT_MAX;
	info->cheapest_element = *stack_a;
	return (info);
}

t_stack *max_element(t_stack *head)
{
	t_stack	*current;
	t_stack *max;

	if (!head)
		return (NULL);
	current = head;
	max = current;
	while (current != NULL)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

t_stack *min_element(t_stack *head)
{
	t_stack	*current;
	t_stack *min;

	if (!head)
		return (NULL);
	current = head;
	min = current;
	while (current != NULL)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}
