/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:51:05 by ccarro-d          #+#    #+#             */
/*   Updated: 2023/01/16 23:08:21 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	int		i;

	chr = c;
	i = ft_strlen(s);
	if (chr == '\0')
		return ((char *)s + i);
	i--;
	while (i >= 0)
	{
		if (s[i] == chr)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
