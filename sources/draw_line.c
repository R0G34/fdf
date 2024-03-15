/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:59:13 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/15 14:11:08 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	my_putpixel(t_fdf *fdf, t_point pixel)
{
	int	mypixel;
	int	alpha;

	alpha = 0;
	if (pixel.axis[X] < MENU_WIDTH)
		alpha = -10;
	if (pixel.axis[X] >= WINX || pixel.axis[Y] >= WINY || \
		pixel.axis[X] < 0 || pixel.axis[Y] < 0)
		return (-1);
	mypixel = ((int)pixel.axis[Y] * WINX * 4) + ((int)pixel.axis[X] * 4);
	if (fdf->img.bitxpixel != 32)
		pixel.color = mlx_get_color_value(fdf->win.mlx, pixel.color);
	apply_color(&fdf->img.addr[mypixel], fdf->img.endian, pixel.color, \
	alpha);
	return (0);
}

int	draw_line(t_fdf *fdf, t_point start, t_point end)
{
	t_point	delta;
	t_point	pixel;
	int		eculidean;
	int		len;

	if (valid_pixel(start) == 0 && valid_pixel(end))
		return (0);
	delta.axis[X] = end.axis[X] - start.axis[X];
	delta.axis[Y] = end.axis[Y] - start.axis[Y];
	eculidean = sqrt((delta.axis[X] * delta.axis[X]) + \
					(delta.axis[Y] * delta.axis[Y]));
	len = eculidean;
	pixel.axis[X] = start.axis[X];
	pixel.axis[Y] = start.axis[Y];
	delta.axis[X] /= eculidean;
	delta.axis[Y] /= eculidean;
	while (eculidean > 0)
	{
		pixel.color = gradient(start.color, end.color, len, len - eculidean);
		my_putpixel(fdf, pixel);
		pixel.axis[X] += delta.axis[X];
		pixel.axis[Y] += delta.axis[Y];
		eculidean--;
	}
	return (0);
}

void	preper_to_draw(t_fdf *fdf, t_point *point)
{
	int	i;
	int	x_end;
	int	y_end;

	i = 0;
	while (i < fdf->map.len)
	{
		if (i % (int)fdf->map.limits.axis[X] != fdf->map.limits.axis[X] - 1)
			x_end = i + 1;
		else
			x_end = -1;
		if (i < fdf->map.len - fdf->map.limits.axis[X])
			y_end = i + fdf->map.limits.axis[X];
		else
			y_end = -1;
		if (point[i].paint)
		{
			if (x_end != -1 && x_end < fdf->map.len)
				draw_line(fdf, point[i], point[x_end]);
			if (y_end != -1 && y_end < fdf->map.len)
				draw_line(fdf, point[i], point[y_end]);
		}
		i++;
	}
}
