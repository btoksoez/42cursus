/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:03:09 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/26 13:28:56 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_position(t_stack **stack)
{
	t_stack	*current;
	int		i;

	if (!stack)
		return ;
	current = *stack;
	i = 1;
	while (current)
	{
		current->position = i;
		current = current->next;
		i++;
	}
}

t_stack	*max_element(t_stack *head)
{
	t_stack	*current;
	t_stack	*max;

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

t_stack	*min_element(t_stack *head)
{
	t_stack	*current;
	t_stack	*min;

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
