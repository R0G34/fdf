/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:21:37 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:26:32 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_z_is_num(char *line, char **arr_words, \
	t_map *map_dots, char **arr_col)
{
	char	*word;
	int		i;

	word = arr_col[0];
	i = 0;
	if (word[i] == '-' || word[i] == '+')
		i++;
	while (word[i])
	{
		if ((word[i] < '0' || word[i] > '9') && word[i] != '\n')
		{
			free(line);
			free_arr(arr_words, map_dots->x);
			free(arr_col);
			map_errors(1, map_dots);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_col_is_num(char *line, char **arr_words, \
	t_map *map_dots, char **arr_col)
{
	char	*word;
	int		i;

	word = arr_col[1];
	i = 0;
	if (word[i] == '0')
		i++;
	if (word[i] == 'x' || word[i] == 'X')
		i++;
	while (word[i] && word[i] != 10 && word[i] != 4)
	{
		if (ft_is_digit_hex(word[i]) < 0)
		{
			free(line);
			free_arr(arr_words, map_dots->x);
			free(arr_col);
			map_errors(3, map_dots);
			return (-1);
		}
		i++;
	}
	return (0);
}

void	ft_map_is_not_rect(char *line, t_map *map_dots)
{
	free(line);
	map_errors(2, map_dots);
}

void	ft_help_func(char *line, char **arr_words, t_map *map_dots)
{
	int		i;
	int		j;
	int		words;
	char	**arr_col;

	i = map_dots->i;
	j = map_dots->j;
	words = ft_count_words(arr_words[j], ',');
	arr_col = ft_split(arr_words[j], ',');
	check_z_is_num(line, arr_words, map_dots, arr_col);
	map_dots->z[i][j] = ft_atoi(arr_col[0]);
	if (arr_col[1])
	{
		check_col_is_num(line, arr_words, map_dots, arr_col);
		map_dots->color_coord[i][j] = ft_atoi_hex(arr_col[1]);
		map_dots->has_color = 1;
	}
	else
		map_dots->color_coord[i][j] = -1;
	free_arr(arr_col, words);
}
