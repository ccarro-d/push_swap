/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_chunks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:08:56 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/03 13:01:06 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_value_index(int *int_lst, int total_size, int value)
{
    int i;

    i = 0;
    while (i < total_size)
    {
        if (value == int_lst[i])
            return (i);
        i++;
    }
    return (0);
}

int to_stack_b(t_data *data, int value_index, int chunk_min, int chunk_max)
{
    int chunk_half;
    
    chunk_half = (chunk_min + chunk_max + 1) / 2;
    pb(data);
    if (value_index < chunk_half)
        rb(data);
    return (1);
}

void    bye_stack_a(t_data *data, int *int_lst, int chunk_size, int total_size)
{
    int value;
    int value_index;
    int chunk_index;
    int chunk_min;
    int chunk_max;
    int pushed;

    chunk_index = 0;
    pushed = 0;
    while (data->size_a > 0)
    {
        value = *(int *)(data->stack_a->content);
        value_index = get_value_index(int_lst, total_size, value);
        chunk_min = chunk_index * chunk_size;
        chunk_max = (chunk_index + 1) * chunk_size - 1;
        if (value_index >= chunk_min && value_index <= chunk_max)
            pushed += to_stack_b(data, value_index, chunk_min, chunk_max);
        else
            ra(data);
        if (pushed >= chunk_size)
        {
            chunk_index++;
            pushed = 0;
        }
    }
}
int get_max_index(t_list *stack_b)
{
    int     index;
    int     max_index;
    int     max_value;
    t_list  *tmp;

    index = 0;
    max_index = index;
    if (!stack_b)
        return (0);
    max_value = *(int *)stack_b->content;
    tmp = stack_b;
    while (tmp)
    {
        if (*(int *)tmp->content > max_value)
        {
            max_value = *(int *)tmp->content;
            max_index = index;
        }
        tmp = tmp->next;
        index++;
    }
    return (max_index);
}

void    return_stack_a(t_data *data)
{
    int max_index;
    
    while (data->size_b > 0)
    {
        max_index = get_max_index(data->stack_b);
        if (max_index <= data->size_b / 2)
        {
            while (max_index--)
                rb(data);
        }
        else
        {
            while (data->size_b > max_index++)
                rrb(data);
        }
    pa(data);
    }
}