/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:56:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/01/31 15:24:59 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_list **stack)
{
    t_list  *first;
    t_list  *second;

    if (!*stack || !(*stack)->next)
        return;
    first = *stack;
    second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    return;
}

void    sa(t_list **stack_a)
{
    sa(stack_a);
    write(1, "sa\n", 3);
    return;
}

void    sb(t_list **stack_b)
{
    sa(stack_b);
    write(1, "sb\n", 3);
    return;
}

void    ss(t_list **stack_a, t_list **stack_b)
{
    sa(stack_a);
    sa(stack_b);
    write(1, "ss\n", 3);
    return;
}
