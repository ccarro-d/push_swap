/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:08:56 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/01 15:23:31 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//Chunks functions

int	*stack_to_array(t_list *stack, int size)
{
    int *array;
    int i;

    array = (int *)malloc(size * sizeof(int));
    if (!array)
        return (NULL);
    i = 0;
    while (stack)
    {
        array[i] = *(int *)stack->content;
        stack = stack->next;
        i++;
    }
    return (array);
}

int get_chunk_size(int size)
{
    // Idea: si size <=20, ¿hacemos "return (size)" sin más?
    if (size <= 100)
        return (size / 5);
    return (size / 11);
}

void    sort_array(int *array, int size_a)
{
    int i;
    int j;
    int aux;

    i = 0;

    while (i < size_a - 1)
    {
        j = 0;
        while (j < (size_a - 1 - i))
        {
            if (array[j] > array[j + 1])
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
            j++;
        }
        i++;
    }
}

int get_chunk_min(int *array, int size_a, int chunk_index, int chunk_size)
{
    int chunk_min;
    chunk_min = chunk_index * chunk_size;
    if (chunk_size >= size_a)
        return (array[chunk_min - 1]);
    return (array[chunk_min])
}
