/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_revrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:55:53 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/01/31 15:25:04 by ccarro-d         ###   ########.fr       */
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

void    rra(t_list **stack_a)
{
    reverse_rotate(stack_a);
    write(1, "rra\n", 4);
    return;
}
void    rrb(t_list **stack_b)
{
    reverse_rotate(stack_b);
    write(1, "rrb\n", 4);
    return;
}
void    rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    write(1, "rrr\n", 4);
    return;    
}
