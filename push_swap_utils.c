/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:08:56 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/03 20:38:17 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_checker(int *int_lst, int size)
{
	int	i;

	i = 0;
	while (i < size - 1 && int_lst[i] < int_lst[i + 1])
		i++;
	if (i == size - 1)
		return (0);
	return (1);
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

void    sort_array(int *int_lst, int size_a)
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
            if (int_lst[j] > int_lst[j + 1])
            {
                aux = int_lst[j];
                int_lst[j] = int_lst[j + 1];
                int_lst[j + 1] = aux;
            }
            j++;
        }
        i++;
    }
}
