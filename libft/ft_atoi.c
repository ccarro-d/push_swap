/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:39:19 by ccarro-d          #+#    #+#             */
/*   Updated: 2024/03/07 22:28:56 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	if (*str >= 48 && *str <= 57)
	{
		while (*str >= 48 && *str <= 57)
		{
			result = (result * 10) + (*str - 48);
			str++;
		}
		if (!*str)
			return (sign * result);
	}
	return (0);
}
