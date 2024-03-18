/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:22:14 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:27:39 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"
#include "../includes/colors.h"
#include "../includes/key.h"

void	ft_2d_rotation(t_map *map_dots)
{
	float	temp_x;
	float	temp_y;

	if (map_dots->isometric == 0)
	{
		temp_x = map_dots->x0;
		temp_y = map_dots->y0;
		map_dots->x0 = temp_x * cos(map_dots->a) - temp_y * sin(map_dots->a);
		map_dots->y0 = temp_x * sin(map_dots->a) + temp_y * cos(map_dots->a);
		temp_x = map_dots->x1;
		temp_y = map_dots->y1;
		map_dots->x1 = temp_x * cos(map_dots->a) - temp_y * sin(map_dots->a);
		map_dots->y1 = temp_x * sin(map_dots->a) + temp_y * cos(map_dots->a);
	}
}

int	ft_x_rotation(t_map *map_dots)
{
	float	temp_y;
	float	temp_z;

	temp_y = map_dots->y0;
	temp_z = map_dots->z0;
	map_dots->y0 = temp_y * cos(map_dots->a) + temp_z * sin(map_dots->a);
	map_dots->z0 = -temp_y * sin(map_dots->a) + temp_z * cos(map_dots->a);
	temp_y = map_dots->y1;
	temp_z = map_dots->z1;
	map_dots->y1 = temp_y * cos(map_dots->a) + temp_z * sin(map_dots->a);
	map_dots->z1 = -temp_y * sin(map_dots->a) + temp_z * cos(map_dots->a);
	return (0);
}

int	ft_y_rotation(t_map *map_dots)
{
	float	x;
	float	z;

	x = map_dots->x0;
	z = map_dots->z0;
	map_dots->x0 = x * cos(map_dots->b) + z * sin(map_dots->b);
	map_dots->z0 = -x * sin(map_dots->b) + z * cos(map_dots->b);
	x = map_dots->x1;
	z = map_dots->z1;
	map_dots->x1 = x * cos(map_dots->b) + z * sin(map_dots->b);
	map_dots->z1 = -x * sin(map_dots->b) + z * cos(map_dots->b);
	return (0);
}

int	ft_z_rotation(t_map *map_dots)
{
	float	x;
	float	y;

	x = map_dots->x0;
	y = map_dots->y0;
	map_dots->x0 = x * cos(map_dots->c) - y * sin(map_dots->c);
	map_dots->y0 = x * sin(map_dots->c) + y * cos(map_dots->c);
	x = map_dots->x1;
	y = map_dots->y1;
	map_dots->x1 = x * cos(map_dots->c) - y * sin(map_dots->c);
	map_dots->y1 = x * sin(map_dots->c) + y * cos(map_dots->c);
	return (0);
}
