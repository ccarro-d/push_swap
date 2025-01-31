/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:36:04 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/01/31 15:22:45 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
    int a;
    int b;
    int c;

    a = *(int *)(*stack_a)->content;
    b = *(int *)(*stack_a)->next->content;
    c = *(int *)(*stack_a)->next->next->content;
    if (a > b && b > c) // 3 2 1
    {
        ra(stack_a);
        sa(stack_a);
    }
    else if (a > b && a > c && b < c) // 3 1 2
        ra(stack_a);
    else if (a > b && a < c) // 2 1 3
        sa(stack_a);
    else if (a < b && b > c && a > c) // 2 3 1
        rra(stack_a);
    else if (a < b && b > c && a < c) // 1 3 2
    {
        rra(stack_a);
        sa(stack_a);
    }
    return;
}
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

void    sort_four_five(t_list **stack_a, int size_a, t_list **stack_b)
{
    int size_b;
    int min_index;

    size_b = 0;
    while (size_a > 3)
    {
        min_index = find_min_index(stack_a);
        if (min_index < size_a / 2)
        {
            while (min_index--)
                ra(stack_a);
        }
        else
        {
            while (size_a > min_index++)
                rra(stack_a);
        }
        pb(stack_a, stack_b); 
        size_a--;
        size_b++;
    }
    sort_three(stack_a);
    while (size_b--)
        pa(stack_a, stack_b);
}

void	push_swap(t_list **stack_a, int size_a, t_list **stack_b)
{
    if (size_a == 2)
        sa(stack_a);
    else if (size_a == 3)
        sort_three(stack_a);
    else if (size_a <= 5)
        sort_four_five(stack_a, size_a, stack_b);
    /*else if (stack_a <= 100)
        sort_one_hundred(stack_a, stack_b);
    else if (stack_a <= 500)
        sort_five_hundred(stack_a, stack_b);*/
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