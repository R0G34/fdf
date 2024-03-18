/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:22:01 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:27:28 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"
#include "../includes/colors.h"
#include "../includes/key.h"

void	ft_zoom(t_map *map_dots, int key)
{
	if (key == KEY_PLUS)
		map_dots->distance += 1;
	if (key == KEY_MINUS)
		map_dots->distance -= 1;
	if (map_dots->distance < 1 && (key == KEY_PLUS || key == KEY_MINUS))
		map_dots->distance = fmin(WIN_WIDTH / map_dots->x / 2, \
			WIN_HEIGHT / map_dots->y / 2);
	if (key == KEY_R)
		map_dots->z_divisor += 0.1;
	if (key == KEY_F)
		map_dots->z_divisor -= 0.1;
	if (map_dots->z_divisor < 0.1 && (key == KEY_F || key == KEY_R))
		map_dots->z_divisor = 1;
}

void	ft_shift(t_map *map_dots, int key)
{
	if (key == KEY_UP)
		map_dots->y_shift -= 10;
	if (key == KEY_DOWN)
		map_dots->y_shift += 10;
	if (key == KEY_RIGHT)
		map_dots->x_shift += 10;
	if (key == KEY_LEFT)
		map_dots->x_shift -= 10;
}

void	ft_iso(int key, t_map *map_dots)
{
	if (key == KEY_3D)
	{
		map_dots->isometric = 1;
		map_dots->x_shift = (WIN_WIDTH - fabs((map_dots->y * map_dots->distance \
			- map_dots->x * map_dots->distance) * cos(map_dots->angle))) / 2;
	}
	if (key == KEY_2D)
	{
		map_dots->isometric = 0;
		ft_default_params(map_dots);
	}
}

void	ft_angle(t_map *map_dots, int key)
{
	if (key == KEY_Q)
		map_dots->a += 0.1;
	else if (key == KEY_A)
		map_dots->a -= 0.1;
	else if (key == KEY_W)
		map_dots->b += 0.1;
	else if (key == KEY_S)
		map_dots->b -= 0.1;
	else if (key == KEY_E)
		map_dots->c += 0.1;
	else if (key == KEY_D)
		map_dots->c -= 0.1;
}

void	ft_change_color(t_map *map_dots, int key)
{
	static int	i = 0;

	if (key == KEY_CMD)
	{
		map_dots->color1_std = WHITE;
		map_dots->color2_std += i;
		map_dots->color3_std += i;
		i++;
	}
}
