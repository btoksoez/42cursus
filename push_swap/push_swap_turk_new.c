/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turk_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/17 13:23:29 by btoksoez         ###   ########.fr       */
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
void	push(FILE *commands, t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	int	count;
	t_stack	*current_b;

	current_b = *stack_b;
//push element at cheapest_element->position to stack_b; get instructions from cost?
	//rotate a
	if (info->cheapest_element->position > (ft_stacksize(*stack_a) / 2))
	{
		count = ft_stacksize(*stack_a) - info->cheapest_element->position + 1;
		while (count-- != 0)
			reverse_rotate(commands, stack_a, 'a');
	}
	else
	{
		count = info->cheapest_element->position - 1;
		while (count-- != 0)
			rotate(commands, stack_a, 'a');
	}
	//rotate b
	if (info->cheapest_element->value > info->bmax->value || info->cheapest_element->value < info->bmin->value)
	{
		if (info->bmax->position > (ft_stacksize(*stack_b) / 2))
		{
			count = ft_stacksize(*stack_b) - info->bmax->position + 1;
			while (count-- != 0)
				reverse_rotate(commands, stack_b, 'b');
		}
		else
		{
			count = info->bmax->position - 1;
			while (count-- != 0)
				rotate(commands, stack_b, 'b');
		}
	}
	else
	{
		while (!(info->cheapest_element->value < current_b->value && info->cheapest_element->value > current_b->next->value))
			current_b = current_b->next;
		if (current_b->position > (ft_stacksize(*stack_b) / 2))
		{
			count = ft_stacksize(*stack_b) - current_b->position + 1;
			while (count-- != 0)
				reverse_rotate(commands, stack_b, 'b');
		}
		else
		{
			count = current_b->position - 1;
			while (count-- != 0)
				rotate(commands, stack_b, 'b');
		}
	}
	push_b(commands, stack_a, stack_b, info);
}

int calculate_between_cost(t_stack *current, t_stack *stack_b, int half_size)
{
    int	cost;
	t_stack	*current_b;

	cost = 0;
	current_b = stack_b;
	while (current->value > current_b->value)
		current_b = current_b->next;
	while (current->value < current_b->value && current_b->next != NULL)
		current_b = current_b->next;
	if (current_b->next == NULL && current->value < current_b->value)
			current_b->position += 1;
	if (current_b->position > half_size)
		cost = half_size - current_b->position + 1;
	else
		cost = current_b->position - 1;
	return (cost);
}

int push_cost(t_stack *current, t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	int	cost;

	if (!stack_a || !stack_b || !(*stack_a) || !current || !info)
		return (0);
	if (!(*stack_b))
		return (1);
	cost = 1;
    if (current->position == 1)
		cost = 1;
	else if (current->position > (ft_stacksize(*stack_a) / 2 + 1))
		cost += ft_stacksize(*stack_a) - current->position + 1;
	else
		cost += current->position - 1;
	if (current->value > info->bmax->value || current->value < info->bmin->value)
	{
		if (info->bmax->position > (ft_stacksize(*stack_b) / 2 + 1))
			cost += ft_stacksize(*stack_b) - info->bmax->position + 1;
		else
			cost += info->bmax->position - 1;
	}
	else
		cost += calculate_between_cost(current, *stack_b, ft_stacksize(*stack_b) / 2 + 1);
	return (cost);
}

void sort(FILE *commands, t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	t_stack	*current;

	if (!stack_a || !*stack_a)
		return ;
	current = *stack_a;
	while (current)
	{
		if (push_cost(current, stack_a, stack_b, info) < info->mincost)
		{
			info->cheapest_element = current;
			info->mincost = push_cost(current, stack_a, stack_b, info);
		}
		if (current->next == NULL)
			break;
		current = current->next;
		update_info(stack_a, stack_b, info);
	}
	push(commands, stack_a, stack_b, info); //push element with lowest cost to right position
	update_info(stack_a, stack_b, info);
}

t_stack	*find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	//go through all elements, add up + correct for rr & rrr, return cheapest
}

void	push_cheapest(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	t_stack	*cheapest;

	assign_steps(stack_a, stack_b, info);
	cheapest = find_cheapest(stack_a, stack_b);
	push(cheapest);
	update_info(&stack_a, &stack_b, info);


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
		while (ft_stacksize(stack_a) > 2)
			push_b(commands, &stack_a, &stack_b, info);		//push all but two numbers to b
		print_test(file, stack_a, 'A', info);
		print_test(file, stack_b, 'B', info);
		push_cheapest(stack_a, stack_b);
		//calculate steps needed for each element and put into struct
			//
		//push back to a
	}

	// free(info);
	fclose(file);
	fclose(commands);
}



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
