/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:21:47 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:26:42 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_map(t_map *map_dots)
{
	int	i;

	i = 0;
	if (map_dots && map_dots->z)
	{
		while (i < map_dots->y)
		{
			if (map_dots->z[i])
				free(map_dots->z[i]);
			if (map_dots->color_coord[i])
				free(map_dots->color_coord[i]);
			i++;
		}
		free(map_dots->z);
		free(map_dots->color_coord);
		free(map_dots);
	}
}
