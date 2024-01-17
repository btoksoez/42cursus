/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/04 20:37:12 by btoksoez         ###   ########.fr       */
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

int find_min(t_stack *head)
{
	t_stack	*current;
	int		min;

	if (!head)
		return (0);
	min = head->value;
	current = head->next;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int find_max(t_stack *head)
{
	t_stack	*current;
	int		max;

	if (!head)
		return (0);
	max = head->value;
	current = head->next;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void rotate(FILE *commands, t_stack **stack, char name, t_info *info)
{
	t_stack *first;
	t_stack *second;
	t_stack *current;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	current = first->next;
	first->next = NULL;
	second->previous = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->previous = current;
	if (name == 'b')
		info->blast = first->value;
	*stack = second;
	fprintf(commands, "r%c\n", name);
}

// void reverse_rotate(FILE *commands, t_stack **stack, char name, t_info *info)
// {
// 	t_stack *first;
// 	t_stack *second;
// 	t_stack *current;

// 	if (!stack || !*stack || !(*stack)->next)
// 		return ;
// 	first = *stack;
// 	second = first->next;
// 	current = first->next;
// 	first->next = NULL;
// 	second->previous = NULL;
// 	while (current->next != NULL)
// 		current = current->next;
// 	if (name == 'b')
// 		info->blast = current->value;
// 	current->next = first;
// 	first->previous = current;
// 	*stack = second;
// 	fprintf(commands, "r%c\n", name);
// }

void push_b(FILE *commands, t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	t_stack	*a1;
	t_stack	*a2;
	t_stack	*b1;

	if (!stack_a || !stack_b)
		return ;
	a1 = *stack_a;
	b1 = *stack_b;
	a2 = a1->next;
	a1->next = b1;
	if (b1 != NULL)
		b1->previous = a1;
	a1->previous = NULL;
	a2->previous = NULL;
	*stack_a = a2;
	*stack_b = a1;
	if (a1->value > info->bmax)
		info->bmax = a1->value;	//update bmax in info
	if (a1->value < info->bmin)
		info->bmin = a1->value;	//update bmin in info
	fprintf(commands, "pb\n");	//print pb
}

void find_pos(element, listb)
{
	//compare a1 with b1, if bigger rotate left, else right
	//push when smaller found
}

t_stack *stackcreate(char *arr[])
{
	t_stack	*stack_a;
	t_stack	*new_element;

	stack_a = NULL;
	//create new list for stack a
	//add each value in arr as new list element in the back
	while (*arr)
	{
		new_element = ft_stacknew(ft_atoi(*arr));
		ft_stackadd_back(&stack_a, new_element);
		arr++;
	}
	return (stack_a);
}

t_info *find_info(t_stack *stack)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->min = find_min(stack);
	info->max = find_max(stack);
	info->bmin = INT_MAX;
	info->bmax = INT_MIN;
	info->blast = find_min(stack);
	return (info);
}

void print_test(FILE *file, t_stack *stack, char stackname, t_info *info)
{
	int	i = 0;
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
	fprintf(file, "\nInfo:\nMin val in info: %d\n", info->min);
	fprintf(file, "max val in info: %d\n", info->max);
	fprintf(file, "bmax val: %d\n", info->bmax);
	fprintf(file, "bmin val: %d\n\n", info->bmin);
	fprintf(file, "blast val: %d\n\n", info->blast);
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
		stack_b = NULL;	//initilize stack_b
		info = find_info(stack_a); //find min
		print_test(file, stack_a, 'a', info);
		print_test(file, stack_b, 'b', info);
		while (stack_a->value != info->min) //rotate until min is at top -> optimize to rotate in the right direction, based on position of min
			rotate(commands, &stack_a, 'a', info);
		print_test(file, stack_a, 'a', info);
		push_b(commands, &stack_a, &stack_b, info);		//push min to b
		push_b(commands, &stack_a, &stack_b, info);		//push a1 to b
		while (stack_a->next != NULL)
		{
			if (stack_a->value > info->bmax)
			{
				while (info->bmax != stack_b->value)	//if a1>bmax
					rotate(commands, &stack_b, 'b', info);
				push_b(commands, &stack_a, &stack_b, info);
				print_test(file, stack_b, 'B', info);
			}

			if (stack_a->value > stack_b->value && stack_a->value < info->blast)
				push_b(commands, &stack_a, &stack_b, info);
			rotate(commands, &stack_b, 'b', info);			//rotate b to right position;
		}
		print_test(file, stack_a, 'A', info);

		//while (b not empty)
			//push b1 to a
		print_test(file, stack_a, 'a', info);
		print_test(file, stack_b, 'b', info);
		free(info);
	}
	fclose(file);
	fclose(commands);
}

//fix libft
//make makefile
//sort functions
//optimize
	//add heuristics function? (cheat could be to just calculate )
	//distance to last number pushed?
	//check if switching a1 and a2 would make sense based on b1 value?
//add position to list

//if top value is smaller than A1 and last element of B is bigger than A1, then push
//fix: rotates, although bmax on top and a1 > bmax
