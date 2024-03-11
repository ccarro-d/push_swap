/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:34:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/03/11 22:07:13 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_arglen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	**ft_argjoin(char **s1, char **s2)
{
	char	**str;
	int		i;
	int		j;

	if (!s1)
		s1 = (char **)ft_calloc(1, sizeof(char *));
	if (!s1 || !s2)
		return (0);
	str = (char **)ft_calloc(ft_arglen(s1) + ft_arglen(s2) + 1, sizeof(char *));
	if (!str)
	{
		free (s1);
		free (s2);
		return (0);
	}
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (str);
}

char	**ft_split_args(char **args, int size)
{
	int		i;
	char	**cpy_args;
	char	**aux;

	i = 0;
	while (i < size)
	{
		if (ft_strchr(args[i], ' '))
		{
			aux = ft_split(args[i], ' ');
			cpy_args = ft_argjoin(cpy_args, aux);
			free (aux);
		}
		else
			cpy_args = ft_argjoin(cpy_args, &args[i]);
		if (!cpy_args)
			return (NULL);
		i++;
	}
	if (*cpy_args)
		return (cpy_args);
	return (args);
}

int	ft_args_checker(char **args, int size)
{
	int		i;
	int		j;

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
	return (i);
}

int	ft_sort_checker(int *int_lst, int size)
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
	return (int_lst);
}

void	ft_parser(char **args, t_list **stack, int size)
{
	int		i;
	char	**cpy_args;
	t_list	*stack_member;
	int		*int_lst;

	i = 0;
	cpy_args = ft_split_args(args, size);
	if (!cpy_args)
		return;
	if (cpy_args != args)
		size = ft_arglen(cpy_args);
	if (ft_args_checker(cpy_args, size) != 0)
	{
		int_lst = ft_transform(cpy_args, size);
		if (!int_lst)
			return (free(cpy_args));
		if (ft_sort_checker(int_lst, size) == 0)
			return ;
		while (i < size)
		{
			stack_member = ft_lstnew(&int_lst[i]);
			ft_lstadd_back(stack, stack_member);
			i++;
		}
	}
	return (free(cpy_args));
}
