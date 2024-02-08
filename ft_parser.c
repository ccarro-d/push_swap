/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:34:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/02/08 23:29:21 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checker(char *args)
{
	int	i;

	i = ft_atoi(args);
	return (i);
}

void	ft_parser(char **args, t_list **stack, int size)
{
	int		i;
	char	*cpy_arg;
	t_list	*stack_member;
	int		checker;

	i = 1;
	while (i <= size)
	{
		cpy_arg = ft_strdup(args[i++]);
		checker = ft_checker(cpy_arg);
		if (checker)
		{
			stack_member = ft_lstnew((void *)cpy_arg);
			ft_lstadd_back(stack, stack_member);
		}
	}
}
