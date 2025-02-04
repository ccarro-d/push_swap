/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:08:20 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/04 20:59:02 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	print_list(void *node) // comentar
{
	printf(BHGRN"  %d\n"END, *((int *)node));
	(void)node;
	return ;
}*/

void	init_data(t_data *data, int argc)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = argc - 1;
	data->size_b = 0;
	data->op_count = 0;
}

int	*handle_input(char **args, int *size, int *int_lst)
{
	if (*size == 1)
		int_lst = parse_single(&args[1], int_lst, size);
	else
		int_lst = parser(&args[1], size, int_lst);
	return (int_lst);
}

void	fill_stack(int *int_lst, t_list **stack, int size)
{
	int		i;
	int		*value;
	t_list	*stack_member;

	i = 0;
	while (i < size)
	{
		value = ft_calloc(1, sizeof(int));
		if (!value)
		{
			free(int_lst);
			return ;
		}
		*value = int_lst[i];
		stack_member = ft_lstnew(value);
		if (!stack_member)
		{
			free(int_lst);
			return ;
		}
		ft_lstadd_back(stack, stack_member);
		i++;
	}
	return ;
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		*stack = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		*int_lst;
	int		lst_size;

	if (argc < 2)
		return (0);
	init_data(&data, argc);
	int_lst = NULL;
	int_lst = handle_input(argv, &data.size_a, int_lst);
	if (!int_lst)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	fill_stack(int_lst, &data.stack_a, data.size_a);
	lst_size = ft_lstsize(data.stack_a);
	if (!data.stack_a || lst_size != data.size_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	// printf(BHMAG"\nASPECTO INICIAL DEL STACK\n\n"END);
	// ft_lstiter(data.stack_a, print_list);
	// printf(BHMAG"\nPUSH_SWAP\n\n"END);
	push_swap(&data, int_lst);
	// printf(BHMAG"\nASPECTO FINAL DEL STACK\n\n"END);
	// ft_lstiter(data.stack_a, print_list);
	// printf("\nNÚMERO FINAL DE OPERACIONES = %d\n", data.op_count);
	free(int_lst);
	free_stack(&data.stack_a);
	return (0);
}
