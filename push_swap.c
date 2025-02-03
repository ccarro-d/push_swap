/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:36:04 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/03 12:54:08 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
    int a;
    int b;
    int c;

    a = *(int *)(data->stack_a)->content;
    b = *(int *)(data->stack_a)->next->content;
    c = *(int *)(data->stack_a)->next->next->content;
    if (a > b && b > c) // 3 2 1
    {
        ra(data);
        sa(data);
    }
    else if (a > b && a > c && b < c) // 3 1 2
        ra(data);
    else if (a > b && a < c) // 2 1 3
        sa(data);
    else if (a < b && b > c && a > c) // 2 3 1
        rra(data);
    else if (a < b && b > c && a < c) // 1 3 2
    {
        rra(data);
        sa(data);
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
                ra(data);
        }
        else
        {
            while (data->size_a > min_index++)
                rra(data);
        }
        pb(data); 
    }
    sort_three(data);
    while (data->size_b)
        pa(data);
    return;
}

void    sort_with_chunks(t_data *data, int *int_lst)
{
    int total_size;
    int chunks_num;
    int chunk_size;

    total_size = data->size_a;
    if (total_size <= 100)
        chunks_num = 5;
    else
        chunks_num = 11;
    chunk_size = (total_size + chunks_num - 1) / chunks_num;
    sort_array(int_lst, data->size_a);
    bye_stack_a(data, int_lst, chunk_size, total_size);
    return_stack_a(data);
}

void	push_swap(t_data *data, int *int_lst)
{
    if (data->size_a == 2)
        sa(data);
    else if (data->size_a == 3)
        sort_three(data);
    else if (data->size_a == 4 || data->size_a == 5)
        sort_four_five(data);
    else if (data->size_a <= 500)
        sort_with_chunks(data, int_lst);
    else
        return;
}
