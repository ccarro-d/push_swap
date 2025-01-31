/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:08:20 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/01/31 12:22:36 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(void *nodo)
{
	printf(BHGRN"%d\n"END, *((int *)nodo));
}
int	*handle_input (char **args, int *size, int *int_lst)
{
	if (*size < 1)
		return 0;
	else if (*size == 1)
		int_lst = ft_parse_single(&args[1], int_lst, size);
	else
		int_lst = ft_parser(&args[1], size, int_lst);
	return (int_lst);
}

void	fill_stack(int *int_lst, t_list **stack, int size)
{
	int		i;
	t_list	*stack_member;

	i = 0;
	while (i < size)
	{
		int *value = malloc(sizeof(int));
		if (!value)
		{
    		free(int_lst);
    		return ;
		}
		*value = int_lst[i];
		stack_member = ft_lstnew(value); // ¿Habría que castear value como void?
		//stack_member = ft_lstnew(&int_lst[i]);
		if (!stack_member)
		{
			free (int_lst);
			return ;
		}
		ft_lstadd_back(stack, stack_member);
		i++;
	}
	free (int_lst);
	return;
}
void	free_stack(t_list **stack)
{
	t_list *tmp;
	while (*stack)
	{
		tmp = (*stack)->next;
		free ((*stack)->content);
		free(*stack);
		*stack = tmp;
		}
}

int	main (int argc, char **argv)
{
	printf("init main\n");
	fflush(stdout);
	t_data	data;
	int		*int_lst;
	int		lst_size;
	int_lst = NULL;
	data.stack_a = NULL;
	data.size_a = argc - 1; 
	printf("data.size_a = %d\n", data.size_a);
	int_lst = handle_input(argv, &data.size_a, int_lst);
	if (!int_lst)
		return 0;
	fill_stack (int_lst, &data.stack_a, data.size_a);
	if (!data.stack_a)
		return (0);
	/* Print node content
	t_list *tmp = data.stack_a;
	while (tmp)
	{
		printf("Node content: %d\n", *(int *)(tmp->content));
		tmp = tmp->next;
	} */
	lst_size = ft_lstsize(data.stack_a);
	printf("lst_size = %d\n", lst_size);
	printf("data_size = %d\n", data.size_a);
	//printf("data-stack_a->content = %d\n", *(int *)data.stack_a->content);
	if (lst_size != data.size_a)
		return (0);
	else
		ft_lstiter(data.stack_a, print_list);
	/*Probando operaciones
	write(1, "\n", 2);
	ra(&data.stack_a);
	ft_lstiter(data.stack_a, print_list);*/
	printf("push_swap\n");
	push_swap(&data.stack_a, data.size_a, &data.stack_b);
	ft_lstiter(data.stack_a, print_list);
	//Fin del programa
	free_stack(&data.stack_a);
	return (0);
}
