/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:56:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/03 11:48:15 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_list **stack_to, t_list **stack_from)
{
    t_list *to_move;
    
    if (!*stack_from)
        return;
    to_move = *stack_from;
    *stack_from = (*stack_from)->next;
    ft_lstadd_front(stack_to, to_move);
    return;
}

void    pa(t_data *data)
{
    if (!data->stack_b)
        return;
    push(&(data->stack_a), &(data->stack_b));
    data->size_a++;
    data->size_b--;
    write(1, "pa\n", 3);
    return;
}

void    pb(t_data *data)
{
    if (!data->stack_a)
        return;
    push(&(data->stack_b), &(data->stack_a));
    data->size_a--;
    data->size_b++;
    write(1, "pb\n", 3);
    return;
}
