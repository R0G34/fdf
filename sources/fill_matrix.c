/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:21:42 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:26:37 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
1) Read 1 line using gnl and find number of columns using ft_split - y;
2) Find number of lines (using gnl) - x;
3) Allocate memory;
4) Fill struct with x, y, z.
Z - numbers in map.
If we find out invalid z in map - free all;BB
*/

static int	fill_matrix_help(t_map *map_dots, int fd)
{
	char	**arr_words;
	char	*line;
	int		words;

	while (map_dots->i < map_dots->y)
	{
		map_dots->j = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		words = ft_count_words(line, ' ');
		if (words != map_dots->x)
			ft_map_is_not_rect(line, map_dots);
		arr_words = ft_split(line, ' ');
		while (map_dots->j < map_dots->x)
		{
			ft_help_func(line, arr_words, map_dots);
			map_dots->j++;
		}
		free(line);
		free_arr(arr_words, map_dots->x);
		map_dots->i++;
	}
	return (0);
}

static int	ft_memalloc(t_map *map_dots, int i)
{
	map_dots->z[i] = malloc(sizeof(int) * (map_dots->x));
	if (!map_dots->z[i])
		ft_free_map(map_dots);
	map_dots->color_coord[i] = malloc(sizeof(int) * (map_dots->x));
	if (!map_dots->color_coord[i])
		ft_free_map(map_dots);
	return (0);
}

static int	fill_matrix_z(t_map *map_dots, char *filename)
{
	int		fd;
	int		i;
	int		**col;

	(map_dots->z) = malloc(sizeof((map_dots->z)) * (map_dots->y));
	if (!*map_dots->z)
		ft_errors(6);
	(col) = malloc(sizeof((col)) * (map_dots->y));
	if (!*col)
		ft_errors(6);
	map_dots->color_coord = col;
	i = 0;
	while (i < map_dots->y)
	{
		ft_memalloc(map_dots, i);
		i++;
	}
	map_dots->i = 0;
	map_dots->j = 0;
	fd = open(filename, O_RDONLY);
	fill_matrix_help(map_dots, fd);
	close(fd);
	return (0);
}

int	check_args(char *file, t_map *map_dots)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map_dots->y = 1;
	map_dots->x = ft_count_words(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		map_dots->y++;
	}
	free(line);
	if (close(fd) == -1)
		ft_errors(5);
	i = 0;
	fill_matrix_z(map_dots, file);
	return (0);
}
