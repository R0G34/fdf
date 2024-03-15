/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:20:32 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/15 14:20:59 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_UTILS_H
# define DRAW_UTILS_H

# include "fdf.h"

int		draw_line(t_fdf *fdf, t_point start, t_point end);
int		gradient(int startcolor, int endcolor, int len, int z);
int		my_putpixel(t_fdf *fdf, t_point pixel);
void	preper_to_draw(t_fdf *fdf, t_point *point);
int		color_value(t_fdf *fdf, int color);
void	apply_color(char *buffer, int endian, int color, int alpha);
int		check_margin(t_point *point, int len);
void	fit_map(t_fdf *fdf, t_point *proyect);
void	render_background(t_fdf *fdf, int backcolor, int menucolor);
void	apply_geo(t_fdf *fdf, t_point *project);

#endif
