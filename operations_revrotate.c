/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_revrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:55:53 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/03 12:45:29 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(t_list **stack)
{
    t_list *last;
    t_list *second_last;

    if (!*stack || !(*stack)->next)
        return;
    last = ft_lstlast(*stack);
    second_last = *stack;
    while (second_last->next != last)
        second_last = second_last->next;
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
    return;
}

void    rra(t_data *data)
{
    if (!data->stack_a || !data->stack_a->next)
        return;
    reverse_rotate(&(data->stack_a));
    write(1, "rra\n", 4);
    data->op_count++;
    return;
}
void    rrb(t_data *data)
{
    if (!data->stack_b || !data->stack_b->next)
        return;
    reverse_rotate(&(data->stack_b));
    write(1, "rrb\n", 4);
    data->op_count++;
    return;
}
void    rrr(t_data *data)
{
    reverse_rotate(&(data->stack_a));
    reverse_rotate(&(data->stack_b));
    write(1, "rrr\n", 4);
    data->op_count++;
    return;    
}
