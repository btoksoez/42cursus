/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/24 16:24:52 by btoksoez         ###   ########.fr       */
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

int main(int argc, char *argv[])
{
	char **res;
	t_stack	*stack_a;
	t_stack	*stack_b;
	FILE *file = fopen("output.txt", "w"); //write output
	FILE *commands = fopen("commands.txt", "w"); //write output
	FILE *original_stdout = stdout;
	freopen("commands.txt", "w", stdout);
	res = parse_args(argc, argv);
	if (!res)
		return (0);
	stack_a = stackcreate(res); //fill stack_a with values
	get_index(stack_a);	//assign optimal position to elements in a
	stack_b = NULL;	//initilize stack_b
	while (ft_stacksize(stack_a) > 2)
		push_b(&stack_a, &stack_b);		//push all but two numbers to b
	print_test(file, stack_a, 'A');
	print_test(file, stack_b, 'B');
	print_test(file, stack_a, 'A');
	print_test(file, stack_b, 'B');
	while (stack_b)
		push_cheapest(&stack_a, &stack_b);
	print_test(file, stack_a, 'A');
	print_test(file, stack_b, 'B');
	final_rotate(&stack_a);
	print_test(file, stack_a, 'A');
	print_test(file, stack_b, 'B');
    fclose(stdout);
    stdout = original_stdout;
	fclose(file);
	fclose(commands);
	free(res);
	//free_stack(stack_a);

	return (0);
}

//free
//fix mistakes that happen
//tester

//sort functions & norminette
//make makefile
