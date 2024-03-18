/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:21:58 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:27:22 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"
#include "../includes/colors.h"
#include "../includes/key.h"

/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
*/
void	ft_init_image(t_map *map_dots)
{
	map_dots->img->image = mlx_new_image(map_dots->mlx_ptr, \
		WIN_WIDTH, WIN_HEIGHT);
	map_dots->img->addr = mlx_get_data_addr(map_dots->img->image, \
		&map_dots->img->bpp, &map_dots->img->size_line, &map_dots->img->endian);
}

void	ft_default_params(t_map *map_dots)
{
	map_dots->distance = fmin(WIN_WIDTH / map_dots->x / 2, \
		WIN_HEIGHT / map_dots->y / 2);
	map_dots->color = WHITE;
	map_dots->color0 = WHITE;
	map_dots->color1 = WHITE;
	map_dots->color1_std = WHITE;
	map_dots->color2_std = DP;
	map_dots->color3_std = DB;
	map_dots->angle = 30 * M_PI / 180;
	map_dots->z_divisor = 1;
	map_dots->y_shift = (WIN_HEIGHT - (map_dots->y) * map_dots->distance) / 2;
	if (map_dots->isometric == 0)
		map_dots->x_shift = (WIN_WIDTH - (map_dots->x) * \
			map_dots->distance) / 2;
	else
		map_dots->x_shift = (WIN_WIDTH - fabs((map_dots->y * map_dots->distance \
			- map_dots->x * map_dots->distance) * cos(map_dots->angle))) / 2;
	map_dots->rotation = 0;
	map_dots->a = 0;
	map_dots->b = 0;
	map_dots->c = 0;
}

void	ft_map_init(t_map *map_dots)
{
	map_dots->mlx_ptr = mlx_init();
	map_dots->win_ptr = mlx_new_window(map_dots->mlx_ptr, \
		WIN_WIDTH, WIN_HEIGHT, "FDF");
	map_dots->isometric = 0;
	ft_default_params(map_dots);
	map_dots->img = malloc(sizeof(t_image));
	if (!map_dots->img)
		ft_errors(6);
	ft_init_image(map_dots);
}

void	ft_new_window(t_map *map_dots)
{
	ft_map_init(map_dots);
	ft_draw_menu(map_dots);
	mlx_key_hook(map_dots->win_ptr, deal_key, (void *)map_dots);
	mlx_hook(map_dots->win_ptr, 17, 1L << 17, ft_close, map_dots);
	mlx_loop(map_dots->mlx_ptr);
}
