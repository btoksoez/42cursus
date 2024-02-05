/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:13:02 by btoksoez          #+#    #+#             */
/*   Updated: 2024/02/05 14:42:52 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

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

int		is_valid_int(const char *str);
int		no_duplicates(int argc, char *argv[]);
int		is_valid(int argc, char *argv[]);
char	**parse_args(int argc, char *argv[]);

void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacknew(int value);
int		ft_stacksize(t_stack *stack);
t_stack	*stackcreate(char *arr[]);

void	update_position(t_stack **stack);
t_stack	*max_element(t_stack *head);
t_stack	*min_element(t_stack *head);
int		ft_arrlen(char **arr);

void	push_b(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack, char stackname, int both);
void	rotate(t_stack **stack, char stackname, int both);
void	swap_stack(t_stack **stack, char stackname);

void	get_index(t_stack *stack_a);
void	assign_index(t_stack *stack_a, int *array);
void	sort_array(int *array, int arraysize);
int		*create_array(t_stack *stack_a);

void	rotations_a(t_stack *current, t_stack *element_a, int stacksize);
void	assign_rotations(t_stack **stack_a, t_stack **stack_b);
void	rotations_b(t_stack *current, int stacksize);
t_stack	*find_smallest_greater(t_stack *stack_a, int index_b);

void	correct_rotations(t_stack *stack_b);
void	correct_rev_rotations(t_stack *stack_b);
void	rotate_push_1(t_stack *current, t_stack **stack_a, t_stack **stack_b);
void	rotate_push_2(t_stack *current, t_stack **stack_a, t_stack **stack_b);
void	push_cheapest(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_cheapest(t_stack *stack_b);
void	set_to_zero(t_stack *stack);

void	final_rotate(t_stack **stack_a);
void	write_stderror(void);
int		is_sorted(t_stack *stack_a);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);

void	sort_small(t_stack **stack_a);
void	head_max(t_stack **stack_a, t_stack *head, t_stack *min);
void	head_min(t_stack **stack_a);
int		free_stack(t_stack *stack);

#endif
