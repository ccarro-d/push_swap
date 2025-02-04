/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:56:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/04 20:00:01 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return ;
}

void	sa(t_data *data)
{
	if (!data->stack_a || !data->stack_a->next)
		return ;
	swap(&(data->stack_a));
	write(1, "sa\n", 3);
	data->op_count++;
	return ;
}

void	sb(t_data *data)
{
	if (!data->stack_b || !data->stack_b->next)
		return ;
	swap(&(data->stack_b));
	write(1, "sb\n", 3);
	data->op_count++;
	return ;
}

void	ss(t_data *data)
{
	swap(&(data->stack_a));
	swap(&(data->stack_b));
	write(1, "ss\n", 3);
	data->op_count++;
	return ;
}
