/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:34:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/02/03 19:41:21 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parser(char **args, t_list **stack, int size)
{
	int	i;
	t_list	*stack_member;

	i = 0;
	while (size > 0)
	{
		stack_member = ft_lstnew((void *)args[size--]);
		ft_lstadd_back(stack, stack_member);
	}
}