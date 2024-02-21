/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:34:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/02/21 21:59:24 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checker(char **args, int size)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		while (*args[i] != '\0')
		{
			if (ft_isdigit(*args[i]) == 0)
				return (0);
			*args[i]++;
		}
		i++;
	}
	return (i);
}

int		*ft_transform(char **args, int size)
{
	int	i;
	int	*int_lst; // RESERVAR MEMORIA?

	i = 1;
	j = 0;
	while (i <= size)
		int_lst[j++] = ft_atoi(args[i++]);
	return (i);
}

void	ft_parser(char **args, t_list **stack, int size)
{
	int		i;
	t_list	*stack_member;
	int		*int_lst;

	i = 1;
	if (ft_checker(args, size) != 0);
	{
		int_lst = ft_transform(args, size);
		while (i <= size)
		{
			stack_member = ft_lstnew((void *)int_lst[i]);
			ft_lstadd_back(stack, stack_member);
			i++;
		}
	}
}
