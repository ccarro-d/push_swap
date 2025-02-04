/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:34:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/04 20:00:13 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_single(char **args, int *int_lst, int *size)
{
	char	**splitted;
	int		i;

	if (!args || !*args || **args == '\0')
		return (NULL);
	splitted = ft_split(*args, ' ');
	if (!splitted)
		return (NULL);
	while (splitted[*size])
		(*size)++;
	int_lst = parser(splitted, size, int_lst);
	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
	if (!int_lst)
		return (NULL);
	return (int_lst);
}

int	args_checker(char **args, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (args[i][j] == '-' || args[i][j] == '+')
				j++;
			if (args[i][j] == '\0' || !ft_isdigit(args[i][j]))
				return (0);
			while (ft_isdigit(args[i][j]))
				j++;
			if (args[i][j] != '\0')
				return (0);
		}
		i++;
	}
	return (1);
}

int	repeat_checker(int *int_lst, int size, int nbr)
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

int	*transform(char **args, int size)
{
	int			i;
	int			j;
	int			*int_lst;
	long long	nbr;

	i = 0;
	j = 0;
	int_lst = (int *)ft_calloc(size, sizeof(int));
	if (!int_lst)
		return (0);
	while (i < size)
	{
		// Comprobar antes de añadir al array si el número no es int o ya está
		nbr = ft_atoi(args[i]);
		if (nbr < -2147483648 || nbr > 2147483647 || repeat_checker(int_lst, j,
				nbr) == 0)
		{
			free(int_lst);
			return (0);
		}
		int_lst[j] = nbr;
		i++;
		j++;
	}
	return (int_lst);
}

int	*parser(char **args, int *size, int *int_lst)
{
	if (args_checker(args, *size) != 0)
	{
		int_lst = transform(args, *size);
		if (!int_lst)
			return (NULL);
	}
	return (int_lst);
}
