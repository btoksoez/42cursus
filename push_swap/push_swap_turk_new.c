/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turk_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/22 17:51:43 by btoksoez         ###   ########.fr       */
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

void print_test(FILE *file, t_stack *stack, char stackname, t_info *info)
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
	fprintf(file, "\nInfo:\n");
    if (info->amin != NULL)
    {
        fprintf(file, "Amin Val: %d\n", info->amin->value);
        fprintf(file, "Amin Pos: %d\n", info->amin->position);
		fprintf(file, "Amin Index: %d\n", info->amin->index);
    }
    if (info->amax != NULL)
    {
        fprintf(file, "Amax Val: %d\n", info->amax->value);
        fprintf(file, "Amax Pos: %d\n", info->amax->position);
		fprintf(file, "Amax Index: %d\n", info->amax->index);
    }
    if (info->bmin != NULL)
    {
        fprintf(file, "Bmin Val: %d\n", info->bmin->value);
        fprintf(file, "Bmin Pos: %d\n", info->bmin->position);
		fprintf(file, "Bmin Index: %d\n", info->bmin->index);
    }
    if (info->bmax != NULL)
    {
        fprintf(file, "Bmax Val: %d\n", info->bmax->value);
        fprintf(file, "Bmax Pos: %d\n", info->bmax->position);
    }
    fprintf(file, "Mincost: %d\n", info->mincost);
    if (info->cheapest_element != NULL)
    {
        fprintf(file, "Cheapest Element Val: %d, Pos: %d\n", info->cheapest_element->value, info->cheapest_element->position);
    }
    fprintf(file, "---------------------------\n\n");
    count++;
}

int main(int argc, char *argv[])
{
	char **res;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;
	FILE *file = fopen("output.txt", "w"); //write output
	FILE *commands = fopen("commands.txt", "w"); //write output
	if (check_input(argv[1]))
	{
		res = ft_split(argv[1], ' ');
		stack_a = stackcreate(res); //fill stack_a with values
		get_index(stack_a);	//assign optimal position to elements in a
		stack_b = NULL;	//initilize stack_b
		info = init_info(&stack_a, &stack_b); //find min
		while (ft_stacksize(stack_a) > 2)
			push_b(&stack_a, &stack_b, info);		//push all but two numbers to b
		print_test(file, stack_a, 'A', info);
		print_test(file, stack_b, 'B', info);
		sort_two(&stack_a);
		update_info(&stack_a, &stack_b, info);
		print_test(file, stack_a, 'A', info);
		print_test(file, stack_b, 'B', info);
		push_cheapest(&stack_a, &stack_b, info);
		print_test(file, stack_a, 'A', info);
		print_test(file, stack_b, 'B', info);
		push_cheapest(&stack_a, &stack_b, info);
		push_cheapest(&stack_a, &stack_b, info);
		push_cheapest(&stack_a, &stack_b, info);
		print_test(file, stack_a, 'A', info);
		print_test(file, stack_b, 'B', info);
		push_cheapest(&stack_a, &stack_b, info);
		push_cheapest(&stack_a, &stack_b, info);
		push_cheapest(&stack_a, &stack_b, info);
		push_cheapest(&stack_a, &stack_b, info);
		push_cheapest(&stack_a, &stack_b, info);
		push_cheapest(&stack_a, &stack_b, info);
		push_cheapest(&stack_a, &stack_b, info);
		push_cheapest(&stack_a, &stack_b, info);
		push_cheapest(&stack_a, &stack_b, info);
		print_test(file, stack_a, 'A', info);
		print_test(file, stack_b, 'B', info);


	}

	// free(info);
	fclose(file);
	fclose(commands);
}

//fix correct_rotations
//make it work with 0

//fix libft
	//fix printf
//make makefile
//sort functions
//free
//fix that it takes separate arguments as args
