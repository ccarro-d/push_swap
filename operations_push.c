/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:56:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/01 14:32:31 by ccarro-d         ###   ########.fr       */
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

void    pa(t_list **stack_a, t_list **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pa\n", 3);
    return;
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    push(stack_b, stack_a);
    write(1, "pb\n", 3);
    return;
}
