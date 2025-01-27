#include "push_swap.h"

void    sa(t_list **stack_a)
{
    t_list  *first;
    t_list  *second;

    if (!*stack_a || !(*stack_a)->next)
        return;
    first = *stack_a;
    second = (*stack_a)->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
    return;
}

void    sb(t_list **stack_b)
{
    sa(stack_b);
    return;
}

void    ss(t_list **stack_a, t_list **stack_b)
{
    t_list  *first_a;
    t_list  *second_a;
    t_list  *first_b;
    t_list  *second_b;

    if (stack_a && (*stack_a)->next)
    {
        first_a = *stack_a;
        second_a = (*stack_a)->next;
        first_a->next = second_a->next;
        second_a->next = first_a;
        *stack_a = second_a;
    }
if (stack_b && (*stack_b)->next)
    {
        first_b = *stack_b;
        second_b = (*stack_b)->next;
        first_b->next = second_b->next;
        second_b->next = first_b;
        *stack_b = second_b;
    }
    return;
}
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
