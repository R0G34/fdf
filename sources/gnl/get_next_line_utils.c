/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:25:04 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:25:07 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

/*The function copies string. Memory is allocated using malloc.*/
/*Return val - NULL if memory wasn't allocated.**
** Otherwise - pointer to duplicated string.*/
char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*dest;

	j = 0;
	i = ft_strlen(str);
	dest = (char *)malloc(sizeof(*dest) * i + 1);
	if (dest == 0)
		return (0);
	while (j < i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

/*The function returns a pointer to the first occurrence** 
**of specified character in string.*/
/*The function returns NULL if the specified character is not found.*/
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

/*Allocates and returns a new string, 
which is the result of the concatenation of ’s1’ and ’s2’*/
char	*ft_strjoin_modified(char const *s1, char const *s2, int len2)
{
	int		len1;
	char	*str;
	int		i;

	if (!s2)
		return (0);
	if (!s1)
		s1 = ft_strdup("");
	i = 0;
	len1 = ft_strlen(s1);
	str = malloc(sizeof(*str) * (len1 + len2) + 1);
	if (str == 0)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (i - len1 <= len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	free((void *)s1);
	return (str);
}
