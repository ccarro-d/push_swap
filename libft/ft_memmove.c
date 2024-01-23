/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:02:44 by ccarro-d          #+#    #+#             */
/*   Updated: 2022/11/26 20:19:13 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = len - 1;
	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	else if (src > dst)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (i >= 0)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	return (dst);
}
