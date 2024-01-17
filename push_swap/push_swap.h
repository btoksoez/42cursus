/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:13:02 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/16 14:13:10 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				position;
	int				index;
	struct s_stack	*previous;
	struct s_stack	*next;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;
}					t_stack;

typedef struct s_info
{
	t_stack	*amin;
	t_stack	*amax;
	t_stack	*bmin;
	t_stack	*bmax;
	int		mincost;
	t_stack	*cheapest_element;
}			t_info;

void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacknew(int value);
int		ft_stacksize(t_stack *stack);
t_stack	*stackcreate(char *arr[]);

void	update_position(t_stack **stack);
t_stack	*max_element(t_stack *head);
t_stack	*min_element(t_stack *head);
t_info	*init_info(t_stack **stack_a, t_stack **stack_b);
void	update_info(t_stack **stack_a, t_stack **stack_b, t_info *info);

void	push_b(FILE *commands, t_stack **stack_a, t_stack **stack_b, t_info *info);
void	reverse_rotate(FILE *commands, t_stack **stack, char name);
void	rotate(FILE *commands, t_stack **stack, char name);

int		find_smallest_but_bigger(t_stack *element_in_a, t_stack *stack_b);

void	get_index(t_stack *stack_a);
void	assign_index(t_stack *stack_a, int *array);
void	sort_array(int *array, int arraysize);
int		*create_array(t_stack *stack_a);



#endif
