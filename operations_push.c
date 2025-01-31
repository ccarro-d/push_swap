/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:56:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/01/31 15:25:18 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list *to_move;
    
    if (!*stack_b)
        return;
    to_move = *stack_b;
    *stack_b = (*stack_b)->next;
    ft_lstadd_front(stack_a, to_move);
    return;
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list *to_move;
    
    if (!*stack_a)
        return;
    to_move = *stack_a;
    *stack_a = (*stack_a)->next;
    ft_lstadd_front(stack_b, to_move);
    return;
}
