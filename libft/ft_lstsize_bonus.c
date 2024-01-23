/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:28:34 by ccarro-d          #+#    #+#             */
/*   Updated: 2023/03/07 22:11:58 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	int		i;

	if (!lst)
		return (0);
	i = 1;
	aux = lst->next;
	while (aux != 0)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}
