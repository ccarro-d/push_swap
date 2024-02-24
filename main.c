/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:08:20 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/02/24 14:51:29 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(void *nodo)
{
	printf("%d\n", *((int *)nodo));
}


int	main (int argc, char **argv)
{
	t_data	data;
	int		args_num;
	int		lst_size;
	
	args_num = argc - 1; 
	if (argc <= 1)
		return (0);
	ft_parser(argv, &data.stack_a, args_num);
	lst_size = ft_lstsize(data.stack_a);
	if (lst_size != args_num)
		return (0);
	else
		ft_lstiter(data.stack_a, print_list);
}