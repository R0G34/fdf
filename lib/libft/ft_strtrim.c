/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:54:14 by abausa-v          #+#    #+#             */
/*   Updated: 2023/10/03 18:50:12 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*result;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	while ((j - 1) && is_in_set(s1[j - 1], set))
		j--;
	if (j < i)
		j = i;
	result = malloc((j - i + 1));
	if (!result)
		return (NULL);
	while (i < j)
		result[k++] = s1[i++];
	result[k] = '\0';
	return (result);
}
