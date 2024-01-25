/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:59:23 by btoksoez          #+#    #+#             */
/*   Updated: 2024/01/25 12:25:36 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_rotations(FILE *rotations, t_stack *stack)
{
    t_stack *current = stack;

    while (current)
    {
        fprintf(rotations, "Value: %d, Index: %d, RA: %d, RB: %d, RRA: %d, RRB: %d, RR: %d, RRR: %d\n",
               current->value, current->index, current->ra, current->rb, current->rra, current->rrb, current->rr, current->rrr);
        current = current->next;
    }
}
