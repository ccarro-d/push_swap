/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:01:14 by ccarro-d          #+#    #+#             */
/*   Updated: 2023/03/16 19:52:07 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (!lst || !del)
		return ;
	while ((*lst) != 0)
	{
		aux = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = aux;
	}
	return ;
}
