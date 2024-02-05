/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/05 09:59:57 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
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

	res = parse_args(argc, argv);
	if (!res)
		return (1);
	stack_a = stackcreate(res);
	get_index(stack_a);
	stack_b = NULL;
	if (is_sorted(stack_a))
		return (0);
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
	free(res);
	free_stack(stack_a);
	return (0);
}
