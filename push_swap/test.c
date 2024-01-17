/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/10 11:20:13 by btoksoez         ###   ########.fr       */
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

void cleanup(commands)
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

// int	cost(t_stack *current, t_stack **stack_a, t_stack **stack_b, t_info *info)
// {
// 	int	cost;
// 	t_stack *current_b;

// 	if (!stack_a || !stack_b || !(*stack_a) || !current || !info)
// 		return (0);
// 	if (!(*stack_b))
// 		return (1);
// 	current_b = *stack_b;
// 	cost = 1; //start with 1 for pb
// 	//ra:rra: based on position of current; if position > number of values in stack_a / 2, then rra;
// 	if (current->position == 1)
// 		cost = 1;
// 	else if (current->position > (ft_stacksize(*stack_a) / 2 + 1))
// 	{
// 		cost += ft_stacksize(*stack_a) - current->position + 1;
// 		printf("Pos in lower half: Cost after rotating a: %d\n", cost);
// 	}
// 	else
// 	{
// 		cost += current->position - 1;
// 		printf("Pos in upper half: Cost after rotating a: %d\n", cost);
// 	}
// 	//rb: based on blast > current > b1 || current > bmax || current <bmin
// 	//rrb: if found position > number of values in stack_b /2, then rrb;
// 	if (current->value > info->bmax->value || current->value < info->bmin->value)
// 	{
// 		printf("if current>bmax");
// 		if (info->bmax->position > (ft_stacksize(*stack_b) / 2 + 1))
// 		{
// 			cost += ft_stacksize(*stack_b) - info->bmax->position + 1;
// 			printf("\nbmax->position: %d, new cost: %d", info->bmax->position, cost);
// 		}
// 		else
// 		{
// 			cost += info->bmax->position - 1;
// 			printf("\nbmax->position: %d, new cost: %d", info->bmax->position, cost);
// 		}
// 		printf("\nFinal cost: %d\n", cost);
// 	}
// 	else
// 	{
// 		printf("value somewhere in between.\nCurrent->value: %d; current_b->value:%d; current_b->next->value: %d", current->value, current_b->value, current_b->next->value);
// 		while (current->value > current_b->value)
// 			current_b = current_b->next;
// 		while (current->value < current_b->value)
// 		{
// 			if (current_b->next == NULL)
// 			{
// 				current_b->position += 1;
// 				break;
// 			}
// 			else
// 				current_b = current_b->next;
// 		}
// 		printf("Value above which a1 needs to be inserted: Val=%d, Pos=%d", current_b->value, current_b->position);
// 		if (current_b->position > (ft_stacksize(*stack_b) / 2 + 1))
// 			cost += ft_stacksize(*stack_b) - current_b->position + 1;
// 		else
// 			cost += current_b->position - 1;
// 		printf("\nFinal cost: %d\n", cost);
// 	}
// 	return (cost);
// }

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
			info->cheapest_element->position = current->position;
			info->mincost = push_cost(current, stack_a, stack_b, info);
		}
		current = current->next;
	}
	//push(commands, stack_a, stack_b, info); //push element with lowest cost to right position
	update_info(stack_a, stack_b, info);
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
    }
    if (info->amax != NULL)
    {
        fprintf(file, "Amax Val: %d\n", info->amax->value);
        fprintf(file, "Amax Pos: %d\n", info->amax->position);
    }
    if (info->bmin != NULL)
    {
        fprintf(file, "Bmin Val: %d\n", info->bmin->value);
        fprintf(file, "Bmin Pos: %d\n", info->bmin->position);
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
	t_stack *current;
	t_info	*info;
	int		c;
	FILE *file = fopen("output.txt", "w"); //write output
	FILE *commands = fopen("commands.txt", "w"); //write output
	if (check_input(argv[1]))
	{
		res = ft_split(argv[1], ' ');
		stack_a = stackcreate(res); //fill stack_a with values
		stack_b = NULL;	//initilize stack_b
		info = init_info(&stack_a, &stack_b); //find min
		push_b(commands, &stack_a, &stack_b, info);		//push two random numbers to b
		push_b(commands, &stack_a, &stack_b, info);
		push_b(commands, &stack_a, &stack_b, info);
		push_b(commands, &stack_a, &stack_b, info);
		print_test(file, stack_a, 'A', info);
		print_test(file, stack_b, 'B', info);
		current = stack_a->next;
		printf("Input to Cost function:\nCurrent pos: %d, val: %d\n", current->position, current->value);
		update_info(&stack_a, &stack_b, info);
		c = push_cost(current, &stack_a, &stack_b, info);
		printf("\nFinal cost: %d", c);
		// while(stack_b) //push all back to a;
		// 	push_a(commands, &stack_b, &stack_a, info);
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
