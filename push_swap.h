/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:32:24 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/02/22 21:28:12 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<unistd.h>
#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include "libft/libft.h"

void	ft_parser(char **args, t_list **stack, int size);
int		*ft_transform(char **args, int size);
int		ft_checker(char **args, int size);
void	print_list(t_list *lst);

#endif