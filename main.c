/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:08:20 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/01/24 21:57:08 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main (int argc, char **argv)
{
	int i;
	t_list	*stack_a;
	t_list	*stack_b;
	
	i = argc - 1;
	(void)stack_b;
	(void)stack_a;
	if (argc <= 1)
		return (0);
	ft_parser(argv, stack_a, i);
	/*new = ft_lstnew(argv[i]);
	ft_lstadd_back(stack_a, new);*/
}