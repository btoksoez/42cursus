/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:03:09 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/05 14:43:38 by btoksoez         ###   ########.fr       */
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

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}
