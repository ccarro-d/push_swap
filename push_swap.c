/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:36:04 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/01 12:06:34 by cesar            ###   ########.fr       */
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
    return;
}
void    sort_one_hundred(t_list **stack_a, int size_a, t_list **stack_b)
{
    int *array;
    int chunk_size;
    int chunk_index;
    int chunk_min;
    int chunk_max;

    array = stack_to_array(*stack_a, size_a);
    if (!array)
        return;
    chunk_size = get_chunk_size(size_a);
    return;
    sort_array(array, size_a);
    chunk_index = 0;
    while (chunk_index < size_a / chunk_size)
    {
        chunk_min = get_chunk_min(array, size_a, chunk_index, chunk_size); 
        chunk_max = chunk_min + chunk_size - 1;
        chunk_index++;
    }
    

}

void	push_swap(t_list **stack_a, int size_a, t_list **stack_b)
{
    if (size_a == 2)
        sa(stack_a);
    else if (size_a == 3)
        sort_three(stack_a);
    else if (size_a == 4 || size_a == 5)
        sort_four_five(stack_a, size_a, stack_b);
    /*El algoritmo de la burbuja sería mejor que los chunks para 6-20 numeros?
    else if (stack_a >=6 && stack_a <= 20)
        sort_twenty(stack_a, stack_b);*/
    else if (stack_a <= 100) //Algoritmo chunks
        sort_one_hundred(stack_a, size_a, stack_b);
    // ¿Podríamos usar los chunks hasta 500?
    /*else if (stack_a <= 500) // Algoritmo radix
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