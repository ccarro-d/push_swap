/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:08:20 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/03/07 23:00:54 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(void *nodo)
{
	printf(BHGRN"%d\n"END, *((int *)nodo));
}


int	main (int argc, char **argv)
{
	t_data	data;
	int		lst_size;
	
	data.size_a = argc - 1; 
	if (argc <= 1)
		return (0);
	ft_parser(argv, &data.stack_a, data.size_a);
	lst_size = ft_lstsize(data.stack_a);
	if (lst_size != data.size_a)
		return (0);
	else
		ft_lstiter(data.stack_a, print_list);
}