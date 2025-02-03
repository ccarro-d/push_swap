/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:56:33 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/03 11:48:55 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_list **stack)
{
    t_list  *first_node;

    if (!*stack || !(*stack)->next)
        return;
    first_node = *stack;
    *stack = (*stack)->next;
    first_node->next = NULL;
    ft_lstadd_back(stack, first_node);
    return;
}

void    ra(t_list **stack_a)
{
    if (!*stack_a || !(*stack_a)->next)
        return;
    rotate(stack_a);
    write(1, "ra\n", 3);
    return;
}
void    rb(t_list **stack_b)
{
    if (!*stack_b || !(*stack_b)->next)
        return;
    rotate(stack_b);
    write(1, "rb\n", 3);
    return;
}
void    rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
    return;    
}
