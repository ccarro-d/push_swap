/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:56:33 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/03 12:45:20 by cesar            ###   ########.fr       */
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

void    ra(t_data *data)
{
    if (!data->stack_a || !data->stack_a->next)
        return;
    rotate(&(data->stack_a));
    write(1, "ra\n", 3);
    data->op_count++;
    return;
}
void    rb(t_data *data)
{
    if (!data->stack_b || !data->stack_b->next)
        return;
    rotate(&(data->stack_b));
    write(1, "rb\n", 3);
    data->op_count++;
    return;
}
void    rr(t_data *data)
{
    rotate(&(data->stack_a));
    rotate(&(data->stack_b));
    write(1, "rr\n", 3);
    data->op_count++;
    return;    
}
