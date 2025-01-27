#include "push_swap.h"

void    rra(t_list **stack_a)
{
    t_list *last;
    t_list *second_last;

    if (!*stack_a || !(*stack_a)->next)
        return;
    last = ft_lstlast(*stack_a);
    second_last = *stack_a;
    while (second_last->next != last)
        second_last = second_last->next;
    second_last->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    return;
}
void    rrb(t_list **stack_b)
{
    rra(stack_b);
    return;
}
void    rrr(t_list **stack_a, t_list **stack_b)
{
    t_list *last_a;
    t_list *second_last_a;
    t_list *last_b;
    t_list *second_last_b;

    if (*stack_a && (*stack_a)->next)
    {
        last_a = ft_lstlast(*stack_a);
        second_last_a = *stack_a;
        while (second_last_a->next != last_a)
            second_last_a = second_last_a->next;
        second_last_a->next = NULL;
        last_a->next = *stack_a;
        *stack_a = last_a;
    }
    if (*stack_b && (*stack_b)->next)
    {
        last_b = ft_lstlast(*stack_b);
        second_last_b = *stack_b;
        while (second_last_b->next != last_b)
            second_last_b = second_last_b->next;
        second_last_b->next = NULL;
        last_b->next = *stack_b;
        *stack_b = last_b;
    }
}
