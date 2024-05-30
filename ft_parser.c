/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:34:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/03/07 22:43:16 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_args_checker(char **args, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= size)
	{
		while (args[i][j] != '\0')
		{
			if (args[i][0] == '-' || args[i][0] == '+')
			{
				while (args[i][j] == '-' || args[i][j] == '+')
					j++;
			}
			if (ft_isdigit(args[i][j]) == 0)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	printf("args_checker returns 1\n");
	return (1);
}

int	ft_sort_checker(int *int_lst, int size)
{
	int	i;

	i = 0;
	while (int_lst[i] < int_lst[i + 1] && i < size)
		i++;
	if (i == size)
		return (0);
	printf("sort_checker returns 1\n");
	return (1);
}

int	ft_repeat_checker(int *int_lst, int size, int nbr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nbr == int_lst[i])
			return (0);
		i++;
	}
	printf("repeat_checker returns 1\n");
	return (1);
}

int	*ft_transform(char **args, int size)
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
		// Comprobar antes de añadir a la lista si el número no es int o ya está
		if (ft_atoi(args[j]) < -2147483648 || ft_atoi(args[j]) > 2147483647
			|| ft_repeat_checker(int_lst, i, ft_atoi(args[j])) == 0)
			return (0);
		// Añadir número a la lista
		int_lst[i] = ft_atoi(args[j]);
		i++;
		j++;
	}
	printf("ft_transform returns %d\n", i);
	return (int_lst);
}

void	ft_parser(char **args, t_list **stack, int size)
{
	int		i;
	t_list	*stack_member;
	int		*int_lst;

	i = 0;
	if (ft_args_checker(args, size) != 0)
	{
		int_lst = ft_transform(args, size);
		if (!int_lst)
			return ;
		if (ft_sort_checker(int_lst, size) == 0)
			return ;
		while (i < size)
		{
			printf("int_lst[%d] = %d\n", i, int_lst[i]);
			stack_member = ft_lstnew(&int_lst[i]);
			ft_lstadd_back(stack, stack_member);
			i++;
		}
		free(int_lst)
	}
}