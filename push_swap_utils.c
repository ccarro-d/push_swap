#include "push_swap.h"

int    find_min_index(t_list **stack_a)
{
    t_list  *current;
    int     min;
    int     index;
    int     min_index;

    current = *stack_a;
    min = *(int *)current->content;
    index = 0;
    min_index = index;
    while (current)
    {
        if (*(int *)current->content < min)
        {
            min = *(int *)current->content;
            min_index = index;
        }
        current = current->next;
        index++;
    }
    return (min_index);
}