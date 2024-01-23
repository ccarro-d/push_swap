/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:08:20 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/01/23 22:33:52 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main (int argc, char **argv)
{
	int i;
	int j[argc - 1];
	t_list	stack_a;
	t_list	stack_b;
	
	i = 1;
	if (argc <= 1)
		return (NULL);
	if (argc = 2)
	{
		*argv = ft_split(argv[1], " ");
		while (*argv++ != "\0");
	}
	while (i < argc)
		ft_parser(*argv[i++]);
	
}