/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:56:06 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/15 10:59:36 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "defines.h"

void	get_color(int max_z, int mini_z, t_point *point, t_colors color);
void	paint(t_map *map);
int		gradient(int startcolor, int endcolor, int len, int z);
int		is_valid_hex_color(const char *color_str);
int		if_hex_color(char *line);
#endif
