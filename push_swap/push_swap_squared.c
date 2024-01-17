/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:58:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/01 11:58:08 by btoksoez         ###   ########.fr       */
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

void rotate(FILE *commands, t_stack **stack, char name)
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
	*stack = second;
	fprintf(commands, "r%c\n", name);
}

void reverse_rotate(t_stack **stack, char name)
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
	*stack = second;
	printf("r%c\n", name);
}

void push(FILE *commands, t_stack **stack_a, t_stack **stack_b, t_info *info, char name)
{
	t_stack	*a1;
	t_stack	*a2;
	t_stack	*b1;

	if (!stack_a || !stack_b)
		return ;
	a1 = *stack_a;
	b1 = *stack_b;
	if (a1->next != NULL)
	{
		a2 = a1->next;
		a2->previous = NULL;
		*stack_a = a2;
	}
	else
		*stack_a = NULL;
	a1->next = b1;
	a1->previous = NULL;
	if (b1 != NULL)
		b1->previous = a1;
	*stack_b = a1;
	if (a1->value > info->bmax)
		info->bmax = a1->value;	//update bmax in info
	if (a1->value < info->bmin)
		info->bmin = a1->value;	//update bmin in info
	fprintf(commands, "p%c\n", name);	//print pb
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
		print_test(file, stack_a, 'a', info);
		while (stack_a->next != NULL)
		{
			while (stack_a->value != info->min) //rotate until min is at top -> optimize to rotate in the right direction, based on position of min
				rotate(commands, &stack_a, 'a');
			push(commands, &stack_a, &stack_b, info, 'b');
			info->min = find_min(stack_a);
		}
		while (stack_b->next != NULL)
			push(commands, &stack_b, &stack_a, info, 'a');
		push(commands, &stack_b, &stack_a, info, 'a');

			// if (stack_a->value > info->bmax)
			// {
			// 	while (info->bmax != stack_b->value)	//if a1>bmax
			// 		rotate(&stack_b, 'b');
			// 	push(&stack_a, &stack_b, info);
			// }
			// if (stack_a->value < find_min(stack_a))		//if a1<bmin
			// {
			// 	while (info->bmax != stack_b->value)
			// 		rotate(&stack_b, 'b');
			// 	push(&stack_a, &stack_b, info);
			// }
			// while (stack_a->value < stack_b->value)
			// 	rotate(&stack_b, 'b');
			// push(&stack_a, &stack_b, info);				//rotate b to right position;
			// 	// if (stack_a->value > stack_b->value)
			// 	// 	push(&stack_a, &stack_b, info);
			print_test(file, stack_a, 'A', info);
			print_test(file, stack_b, 'B', info);
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
//add position to list
