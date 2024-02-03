/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:08:20 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/02/03 19:46:47 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *lst)
{
	t_list	*aux;
	size_t	lst_size;

	aux = lst;
	lst_size = ft_lstsize(lst);
	while (lst_size > 0)
	{
		printf("%s\n", (char *)lst->content);
		lst_size--;
	}
}

int	main (int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	(void)stack_b;
	if (argc <= 1)
		return (0);
	ft_parser(argv, &stack_a, argc - 1);
	print_list(stack_a);
}