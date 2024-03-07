/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:32:24 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/03/07 21:11:24 by ccarro-d         ###   ########.fr       */
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
# define END   "\e[0m"

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
}	t_data;

void	ft_parser(char **args, t_list **stack, int size);
int		*ft_transform(char **args, int size);
int		ft_args_checker(char **args, int size);
void	print_list(void *nodo);

#endif