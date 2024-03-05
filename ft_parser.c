/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:34:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/03/05 21:05:19 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_args_checker(char **args, int size)
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

int		ft_sort_checker(int *int_lst, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (int_lst[i] < int_lst[j] && i < size)
	{
		i++;
		j++;
	}
	return (j - size);
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
		// Comprobar antes de añadir a la lista si el número ya está
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
	if (ft_args_checker(args, size) != 0)
	{
		int_lst = ft_transform(args, size);
		if (!int_lst)
			return;
		if (ft_sort_checker(int_lst, size) == 0)
			return;
		while (i < size)
		{
			stack_member = ft_lstnew(&int_lst[i]);
			ft_lstadd_back(stack, stack_member);
			i++;
		}
	}
}
