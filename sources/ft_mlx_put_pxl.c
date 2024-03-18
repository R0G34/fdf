/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_put_pxl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:21:54 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:27:02 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"
#include "../includes/colors.h"
#include "../includes/key.h"

/*
Source: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
*/
void	my_mlx_pixel_put(t_map *map_dots, int x, int y)
{
	char	*dst;

	dst = map_dots->img->addr + (y * map_dots->img->size_line + \
		x * (map_dots->img->bpp / 8));
	*(unsigned int *)dst = map_dots->color;
}
