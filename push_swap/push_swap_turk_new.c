/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turk_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/18 14:31:28 by btoksoez         ###   ########.fr       */
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

void cleanup(FILE *commands)
{
	//merge rra and rrb etc to rrall
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
        fprintf(file, "Element %d: %d\n", i, copy->value);
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
		while (ft_stacksize(stack_a) > 5)
			push_b(&stack_a, &stack_b, info);		//push all but two numbers to b
		print_test(file, stack_a, 'A', info);
		print_test(file, stack_b, 'B', info);
		push_cheapest(stack_a, stack_b, info);
		print_test(file, stack_b, 'B', info);

		//figure out if rotate_push works
	}

	// free(info);
	fclose(file);
	fclose(commands);
}


//something with the rotations does't work yet, with b1>amax values;
//check again if rottations are correct
//fix sort

//fix libft
	//fix printf
//make makefile
//sort functions
//free
//fix that it takes separate arguments as args
//optimize
	//add heuristics function? (cheat could be to just calculate )
	//distance to last number pushed?
	//check if switching a1 and a2 would make sense based on b1 value?
	//could add separete functions like addfront, delete_end .. )
//add position to list


//if top value is smaller than A1 and last element of B is bigger than A1, then push
//fix: rotates, although bmax on top and a1 > bmax

//make functions that calculate for each number in stack_a how many steps it would take to make it bmax;
	//need to return int cost;
	//calls all functions ra, rr, ... until is_sorted=true; randomly? how to know which ones to call?
	//function returning true or false: is_sorted() -> checks if stack is correctly sorted
	//
//count rotations of a and b as 1 step;
	//if ra & rb -> res - 1;
//go through all numbers in a
//push back
