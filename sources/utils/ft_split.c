/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:25:39 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:25:42 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*Allocates and returns an array of strings obtained by splitting ’s’ 
using the character ’c’ as a delimiter. 
The array must be ended by a NULL pointer.*/
/*Approach:
1) Count words (count_words);
2) Allocate memory to array, which will contain "count_words" items;
3) For each word count length, allocate memory in array for that len;
4) Fill array with words.*/
int	ft_count_words(char const *line, char ch)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (line[i] && line[i] != 10)
	{
		if (line[i] != ch && line[i] != 10 && line[i] != '\n')
		{
			words++;
			i++;
		}
		while (line[i] != ch && line[i] && line[i] != 10)
			i++;
		while (line[i] == ch)
			i++;
	}
	return (words);
}

static int	count_len(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

void	free_arr(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char **)malloc(sizeof(arr) * (ft_count_words(s, c) + 1));
	if (arr == 0)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_count_words(s, c))
	{
		while (s[j] == c)
			j++;
		arr[i] = ft_substr(&s[j], 0, count_len(&s[j], c));
		if (arr[i] == NULL)
		{
			free_arr(arr, i);
			return (NULL);
		}
		j = j + count_len(&s[j], c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
