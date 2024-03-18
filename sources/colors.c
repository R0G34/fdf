/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:20:59 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:21:27 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/colors.h"
#include "../includes/key.h"

void	ft_define_color(t_map *map_dots)
{
	if (map_dots->z0 < 0)
		map_dots->color_coord[(int)map_dots->y0][(int)map_dots->x0] \
			= map_dots->color3_std;
	if (map_dots->z0 == 0)
		map_dots->color_coord[(int)map_dots->y0][(int)map_dots->x0] \
			= map_dots->color1_std;
	if (map_dots->z0 > 0)
		map_dots->color_coord[(int)map_dots->y0][(int)map_dots->x0] \
			= map_dots->color2_std;
	if (map_dots->z1 < 0)
		map_dots->color_coord[(int)map_dots->y1][(int)map_dots->x1] \
			= map_dots->color3_std;
	if (map_dots->z1 == 0)
		map_dots->color_coord[(int)map_dots->y1][(int)map_dots->x1] \
			= map_dots->color1_std;
	if (map_dots->z1 > 0)
		map_dots->color_coord[(int)map_dots->y1][(int)map_dots->x1] \
			= map_dots->color2_std;
}

void	ft_set_color(t_map *map_dots)
{
	int	a;
	int	b;

	a = map_dots->color_coord[(int)map_dots->y0][(int)map_dots->x0];
	b = map_dots->color_coord[(int)map_dots->y1][(int)map_dots->x1];
	map_dots->color0 = a;
	map_dots->color1 = b;
}

static int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static double	percent(t_map *map_dots)
{
	double	placement;
	double	distance;

	if (map_dots->deltax > map_dots->deltay)
	{
		placement = map_dots->x0 - map_dots->x_start;
		distance = map_dots->x1 - map_dots->x_start;
	}
	else
	{
		placement = map_dots->y0 - map_dots->y_start;
		distance = map_dots->y1 - map_dots->y_start;
	}
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	get_color(t_map *map_dots)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (map_dots->color0 == map_dots->color1)
		return (map_dots->color0);
	percentage = percent(map_dots);
	red = get_light((map_dots->color0 >> 16) & 0xFF, \
		(map_dots->color1 >> 16) & 0xFF, percentage);
	green = get_light((map_dots->color0 >> 8) & 0xFF, \
		(map_dots->color1 >> 8) & 0xFF, percentage);
	blue = get_light(map_dots->color0 & 0xFF, \
		map_dots->color1 & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
