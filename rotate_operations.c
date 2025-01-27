#include "push_swap.h"

void    ra(t_list **stack_a)
{
    t_list  *first_node;

    if (!*stack_a || !(*stack_a)->next)
        return;
    first_node = *stack_a;
    *stack_a = (*stack_a)->next;
    first_node->next = NULL;
    ft_lstadd_back(stack_a, first_node);
    return;
}
void    rb(t_list **stack_b)
{
    ra(stack_b);
    return;
}
void    rr(t_list **stack_a, t_list **stack_b)
{
    t_list  *first_node_a;
    t_list  *first_node_b;

    if (*stack_a && (*stack_a)->next)
    {
        first_node_a = *stack_a;
        *stack_a = (*stack_a)->next;
        first_node_a->next = NULL;
        ft_lstadd_back(stack_a, first_node_a);
    }
        if (*stack_b && (*stack_b)->next)
    {
        first_node_b = *stack_b;
        *stack_b = (*stack_b)->next;
        first_node_b->next = NULL;
        ft_lstadd_back(stack_b, first_node_b);
    }
    return;
}
