/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:36:04 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/02 21:36:19 by cesar            ###   ########.fr       */
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

void    sort_four_five(t_data *data)
{
    int min_index;

    while (data->size_a > 3)
    {
        min_index = find_min_index(&(data->stack_a));
        if (min_index < data->size_a / 2)
        {
            while (min_index--)
                ra(&(data->stack_a));
        }
        else
        {
            while (data->size_a > min_index++)
                rra(&(data->stack_a));
        }
        pb(data); 
    }
    sort_three(&(data->stack_a));
    while (data->size_b)
        pa(data);
    return;
}

void    sort_with_chunks(t_data *data, int *int_lst)
{
    int total_size;
    int chunk_size;

    total_size = data->size_a;
    chunk_size = get_chunk_size(total_size);
    sort_array(int_lst, data->size_a);
    bye_stack_a(data, int_lst, chunk_size, total_size);
    printf("\nstack_b antes de devolverlo a stack_a\n");
    write(1, "\n", 1);
    ft_lstiter(data->stack_b, print_list); //comentar
    printf("\npush desde stack_b a stack_a\n");
    write(1, "\n", 1);
    return_stack_a(data);
    printf("\nnuevo orden stack_a\n");
    write(1, "\n", 1);
    ft_lstiter(data->stack_a, print_list); //comentar
}

void	push_swap(t_data *data, int *int_lst)
{
    if (data->size_a == 2)
        sa(&(data->stack_a));
    else if (data->size_a == 3)
        sort_three(&(data->stack_a));
    else if (data->size_a == 4 || data->size_a == 5)
        sort_four_five(data);
    else if (data->size_a <= 500)
        sort_with_chunks(data, int_lst);
    else
        return;
}
