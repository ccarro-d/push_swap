#include "push_swap.h"

void	sort_three(t_list **stack_a, t_list **stack_b)
{
    if ((*stack_a)->content > (*stack_a)->next->content)
    {
        if ((*stack_a)->content < (*stack_a)->next->next->content)
            sa(stack_a);
        else
            ra(stack_a);
        if ((*stack_a)->content > (*stack_a)->next->content)
            ra(stack_a);
    }
    else
    {
        rra(stack_a);
        if ((*stack_a)->content > (*stack_a)->next->content)
            sa(stack_a);
    }

}

void	push_swap(t_list **stack_a, int size_a, t_list **stack_b)
{
    if (size_a == 2)
        sa(stack_a);
    else if (size_a == 3)
        sort_three(stack_a, stack_b);
    else if (size_a <= 5)
        sort_four_or_five(stack_a);
    else if (stack_a <= 100)
        sort_up_to_hundred(stack_a);
    else if (stack_a <= 500)
        sort_up_to_five_hundred(stack_a);
    else
        return;
}
/*
//Posibles combinaciones
1   2   2   3   3
3   1   3   2   1
2   3   1   1   2



//Caso 1
3
2
1

2          ra
1
3

1          sa
2
3

//Caso 2
3
1
2

1          ra
2
3

//Caso 3
2
1
3

1         sa
2
3

// Caso 4
2
3
1

1           rra
2
3

//Caso 5
1
3
2

2           rra
1
3

1           sa
2
3
*/