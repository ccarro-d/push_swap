/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:34:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/02/24 14:02:55 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checker(char **args, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= size)
	{
		while (args[i][j] != '\0')
		{
			if (ft_isdigit(args[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		*ft_transform(char **args, int size)
{
	int	i;
	int	j;
	int	*int_lst;

	i = 0;
	j = 1;
	int_lst = (int *)ft_calloc(size, sizeof(int));
	if (!int_lst)
		return (0);
	while (i < size)
	{
		int_lst[i] = ft_atoi(args[j]);
		i++;
		j++;
		
	}
	return (int_lst);
}

void	ft_parser(char **args, t_list **stack, int size)
{
	int		i = 1;
	t_list	*stack_member;
	int		*int_lst;
	i = 0;
	if (ft_checker(args, size) != 0)
	{
		int_lst = ft_transform(args, size);
		if (!int_lst)
			return;
		while (i < size)
		{
			stack_member = ft_lstnew(&int_lst[i]);
			ft_lstadd_back(stack, stack_member);
			i++;
		}
	}
}
