/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:21:33 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:26:28 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/colors.h"
#include "../includes/key.h"

void	ft_draw_line(t_map *map_dots)
{
	float	deltax;
	float	deltay;
	float	max;

	ft_set_coord(map_dots);
	deltax = (float)(map_dots->x1 - map_dots->x0);
	deltay = (float)(map_dots->y1 - map_dots->y0);
	max = (float)fmax(fabs((double)deltax), fabs((double)deltay));
	deltay = deltay / max;
	deltax = deltax / max;
	while ((int)(map_dots->x1 - map_dots->x0) || \
		(int)(map_dots->y1 - map_dots->y0))
	{
		if (map_dots->x0 >= WIN_WIDTH || map_dots->y0 >= WIN_HEIGHT || \
				map_dots->x0 < 0 || map_dots->y0 < 0)
			break ;
		map_dots->color = get_color(map_dots);
		my_mlx_pixel_put(map_dots, map_dots->x0, map_dots->y0);
		map_dots->x0 += deltax;
		map_dots->y0 += deltay;
	}
}

static void	ft_horiz_line(t_map *map_dots)
{
	map_dots->x1 = map_dots->x0 + 1;
	map_dots->y1 = map_dots->y0;
	ft_draw_line(map_dots);
}

static void	ft_vert_line(t_map *map_dots)
{
	map_dots->x1 = map_dots->x0;
	map_dots->y1 = map_dots->y0 + 1;
	ft_draw_line(map_dots);
}

void	ft_draw_map(t_map *map_dots)
{
	float	x0;
	float	y0;

	y0 = 0;
	while (y0 < (float)map_dots->y)
	{
		x0 = 0;
		while (x0 < (float)map_dots->x)
		{
			map_dots->x0 = x0;
			map_dots->y0 = y0;
			if (x0 < map_dots->x - 1)
				ft_horiz_line(map_dots);
			map_dots->x0 = x0;
			map_dots->y0 = y0;
			if (y0 < map_dots->y - 1)
				ft_vert_line(map_dots);
			x0++;
		}
		y0++;
	}
	mlx_put_image_to_window(map_dots->mlx_ptr, map_dots->win_ptr, \
		map_dots->img->image, 0, 0);
}
