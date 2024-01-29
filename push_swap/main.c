/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/29 09:51:08 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_test(FILE *file, t_stack *stack, char stackname)
{
	int	i = 1;
	static int count = 1;
	t_stack *copy = stack;
	fprintf(file, "Stack %c Test %d:\n", stackname, count);
	if (copy == NULL)
		fprintf(file, "Stack->NULL\n");
    while (copy)
    {
        fprintf(file, "Element %d: %d, Pos: %d, Index: %d\n", i, copy->value, copy->position, copy->index);
        copy = copy->next;
        i++;
    }
}

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

int main(int argc, char *argv[])
{
	char **res;
	t_stack	*stack_a;
	t_stack	*stack_b;
	FILE *file = fopen("output.txt", "w"); //write output
	FILE *commands = fopen("commands.txt", "w"); //write output
	res = parse_args(argc, argv);
	if (!res)
		return (1);
	stack_a = stackcreate(res); //fill stack_a with values
	get_index(stack_a);	//assign optimal position to elements in a
	stack_b = NULL;	//initilize stack_b
	print_test(file, stack_a, 'A');
	if (is_sorted(stack_a))
		return (0);
	while (ft_stacksize(stack_a) > 2)
		push_b(&stack_a, &stack_b);		//push all but two numbers to b
	while (stack_b)
		push_cheapest(&stack_a, &stack_b);
	final_rotate(&stack_a);
	print_test(file, stack_a, 'A');
	print_test(file, stack_b, 'B');
	if (is_sorted(stack_a))
		fprintf(file, "Sorted.\n");
	else
		fprintf(file, "Failed.\n");
	fclose(file);
	fclose(commands);
	free(res);
	free_stack(stack_a);
	return (0);
}

//free
//tester
//make sort small function
