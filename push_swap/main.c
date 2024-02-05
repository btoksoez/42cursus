/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/05 10:28:07 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_stacksize(stack_a) <= 3)
		sort_small(&stack_a);
	else
	{
		while (ft_stacksize(stack_a) > 2)
			push_b(&stack_a, &stack_b);
		while (stack_b)
			push_cheapest(&stack_a, &stack_b);
		final_rotate(&stack_a);
	}
}

int	is_sorted(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current)
	{
		if (current->position != current->index)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char	**res;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	res = parse_args(argc, argv);
	if (!res)
	{
		free (res);
		return (0);
	}
	stack_a = stackcreate(res);
	get_index(stack_a);
	stack_b = NULL;
	if (is_sorted(stack_a))
		return (0);
	ft_sort(stack_a, stack_b);
	free(res);
	free_stack(stack_a);
	return (0);
}
