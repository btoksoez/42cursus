/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/12 11:12:37 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void print_stack(t_stack *stack)
// {
// 	while (stack != NULL)
// 	{
// 		ft_printf("%d\n", stack->value);
// 		stack = stack->next;
// 	}
// }
//
int	free_stack(t_stack *stack)
{
	t_stack	*node;
	t_stack	*next;

	if (!stack)
		return (0);
	node = stack;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	return (0);
}

void	ft_sort(t_stack **stack_a, t_stack *stack_b)
{
	if (ft_stacksize(*stack_a) <= 3)
		sort_small(stack_a);
	else
	{
		while (ft_stacksize(*stack_a) > 2)
			push_b(stack_a, &stack_b);
		while (stack_b)
			push_cheapest(stack_a, &stack_b);
		final_rotate(stack_a);
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
		return (0);
	stack_a = stackcreate(res);
	free_arr(res);
	if (!stack_a)
		return (free_stack(stack_a));
	get_index(stack_a);
	stack_b = NULL;
	if (!is_sorted(stack_a))
		ft_sort(&stack_a, stack_b);
	free_stack(stack_a);
	return (0);
}
