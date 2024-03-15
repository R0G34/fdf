/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:28:19 by abausa-v          #+#    #+#             */
/*   Updated: 2023/09/28 13:05:53 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;

	if (dst == src || !n)
		return (dst);
	if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			*(char *)(dst + i) = *(const char *)(src + i);
			i++;
		}
	}		
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			*(char *)(dst + i) = *(const char *)(src + i);
		}
	}
	return (dst);
}	
