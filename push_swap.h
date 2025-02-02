/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:32:24 by ccarro-d          #+#    #+#             */
/*   Updated: 2025/02/02 21:33:03 by cesar            ###   ########.fr       */
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
//# define END   "\e[0m"
# define END   "\x1b[0m"

#include<unistd.h>
#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include "libft/libft.h"

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;
	int		size_b;
	int		op_count;
}	t_data;

// Parser
int		*handle_input (char **args, int *size, int *int_lst);
int		*ft_parser(char **args, int *size, int *int_lst);
int		*ft_parse_single(char **args, int *int_lst, int *size);
int		*ft_transform(char **args, int size);
int		ft_sort_checker(int *int_lst, int size);
int		ft_repeat_checker(int *int_lst, int size, int nbr);
int		ft_args_checker(char **args, int size);
void	fill_stack(int *int_lst, t_list **stack, int size);
void	print_list(void *nodo); // comentar eventualmente
//Operations
void    swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void    push(t_list **stack_a, t_list **stack_b);
void    pa(t_data *data);
void    pb(t_data *data);
void    rotate(t_list **stack);
void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);
void    reverse_rotate(t_list **stack);
void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);

//Push_swap
void	push_swap(t_data *data, int *int_lst);
void	sort_three(t_list **stack_a);
int		find_min_index(t_list **stack_a);
void    sort_four_five(t_data *data);
void    sort_with_chunks(t_data *data, int *int_lst);
int		*stack_to_array(t_list *stack, int size);
int		get_chunk_size(int size);
void    sort_array(int *int_lst, int size_a);
int		get_value_index(int *int_lst, int total_size, int value);
int		to_stack_b(t_data *data, int value_index, int chunk_min, int chunk_max);
void    bye_stack_a(t_data *data, int *int_lst, int chunk_size, int total_size);
int		get_max_index(t_list *stack_b);
void	return_stack_a(t_data *data);

#endif