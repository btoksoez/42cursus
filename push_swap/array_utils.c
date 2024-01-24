/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:12:02 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/23 10:36:13 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	*create_array(t_stack *stack_a)
{
	int		*array;
	int		i;
	t_stack	*current;

	current = stack_a;
	array = (int *)malloc(sizeof(int) * ft_stacksize(stack_a));
	if (!array)
		return (NULL);
	i = 0;
	while (current->next != NULL)
	{
		array[i++] = current->value;
		current = current->next;
	}
	array[i] = current->value;
	return (array);
}

void	swap(int *a, int *b)
{
	int	temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_array(int *array, int arraysize)
{
	int	j;
	int	swapped;

	if (!array)
		return ;
	j = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		j = 0;
		while (j < arraysize - 1)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
			}
			j++;
		}
	}
}

void	assign_index(t_stack *stack_a, int *array)
{
	int	i;
	int	stacksize;

	stacksize = ft_stacksize(stack_a);

	while (stack_a)
	{
		i = 0;
		while (i < stacksize)
		{
			if (array[i] == stack_a->value)
			{
				stack_a->index = i + 1;
				break ;
			}
			i++;
		}
		stack_a = stack_a->next;
	}
}

void	get_index(t_stack *stack_a)
{
	int *array;

	array = create_array(stack_a);
	sort_array(array, ft_stacksize(stack_a));
	assign_index(stack_a, array);
	free(array);
}
