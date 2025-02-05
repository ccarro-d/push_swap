/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:32:24 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/05 19:21:48 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BHBLK "\e[1;90m"
# define BHRED "\e[1;91m"
# define BHGRN "\e[1;92m"
# define BHYEL "\e[1;93m"
# define BHBLU "\e[1;94m"
# define BHMAG "\e[1;95m"
# define BHCYN "\e[1;96m"
# define BHWHT "\e[1;97m"
# define END "\e[0m"

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;
	int		size_b;
	int		op_count;
}			t_data;

// Parser
void		init_data(t_data *data, int argc);
int			*handle_input(char **args, int *size, int *int_lst);
int			*parse_single(char **args, int *int_lst, int *size);
int			*parser(char **args, int *size, int *int_lst);
int			args_checker(char **args, int size);
int			*transform(char **args, int size);
int			repeat_checker(int *int_lst, int size, int nbr);
void		fill_stack(int *int_lst, t_list **stack, int size);
//void	print_list(void *node);

// Operations
void		swap(t_list **stack);
void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		push(t_list **stack_a, t_list **stack_b);
void		pa(t_data *data);
void		pb(t_data *data);
void		rotate(t_list **stack);
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		reverse_rotate(t_list **stack);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);

// Sorting
void		push_swap(t_data *data, int *int_lst);
int			sort_checker(int *int_lst, int size);
void		sort_three(t_data *data);
void		sort_four_five(t_data *data);
int			find_min_index(t_list **stack_a);
void		sort_with_chunks(t_data *data, int *int_lst);
int			*stack_to_array(t_list *stack, int size);
void		sort_array(int *int_lst, int size_a);
int			get_value_index(int *int_lst, int total_size, int value);
int			to_stack_b(t_data *data, int value_index, int chunk_index,
				int chunk_size);
void		bye_stack_a(t_data *data, int *int_lst, int chunk_size,
				int total_size);
int			get_max_index(t_list *stack_b);
void		return_stack_a(t_data *data);

#endif