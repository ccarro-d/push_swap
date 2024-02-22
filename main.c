/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:08:20 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/02/22 22:10:28 by ccarro-d         ###   ########.fr       */
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
		printf("%d\n", *((int *)(aux->content)));
		aux=aux->next;
		lst_size--;
	}
}

int	main (int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		args_num;
	int		lst_size;
	
	args_num = argc - 1; 
	(void)stack_b;
	if (argc <= 1)
		return (0);
	ft_parser(argv, &stack_a, args_num);
	lst_size = ft_lstsize(stack_a);
	if (lst_size != args_num)
		return (0);
	else
		print_list(stack_a);
}