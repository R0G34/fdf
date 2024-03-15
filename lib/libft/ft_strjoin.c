/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:19:08 by abausa-v          #+#    #+#             */
/*   Updated: 2023/10/03 08:52:38 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		ls1;
	int		ls2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * ls1 + ls2 + 1);
	if (!result)
		return (NULL);
	while (ls1--)
	{
		result[i] = s1[i];
		i++;
	}
	ls1 = i;
	i = 0;
	while (ls2--)
		result[ls1++] = s2[i++];
	result[ls1] = '\0';
	return (result);
}
