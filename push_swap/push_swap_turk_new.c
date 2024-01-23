/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turk_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/23 09:55:31 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int check_input(char *arr)
{
	//is it only numbers
	//is there input
	//no duplicates
	return (1);
}

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

int main(int argc, char *argv[])
{
	char **res;
	t_stack	*stack_a;
	t_stack	*stack_b;
	FILE *file = fopen("output.txt", "w"); //write output
	FILE *commands = fopen("commands.txt", "w"); //write output
	FILE *original_stdout = stdout;
	freopen("commands.txt", "w", stdout);
	if (check_input(argv[1]))
	{
		res = ft_split(argv[1], ' ');
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
	}
    fclose(stdout);
    stdout = original_stdout;

	// free(info);
	fclose(file);
	fclose(commands);
}

//make it work with 0
//fix that it takes separate arguments as args
//free
//tester

//sort functions
//fix libft
	//fix printf
//make makefile



