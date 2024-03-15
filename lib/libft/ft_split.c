/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:12:58 by abausa-v          #+#    #+#             */
/*   Updated: 2023/10/04 10:06:36 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sublen(const char *s, char c)
{
	size_t	res;

	res = 0;
	while (*s)
	{
		if (*s != c)
		{
			++res;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	res = malloc(sizeof(char *) * (ft_sublen(s, c) + 1));
	if (!res)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			res[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	res[i] = 0;
	return (res);
}
