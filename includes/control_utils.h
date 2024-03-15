/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:22:00 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/15 14:35:03 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_UTILS_H
# define CONTROL_UTILS_H

# include "defines.h"

void	angle_control(int key, t_fdf *fdf);
void	angle(float *ang, float value);
int		terminate_program(void *param);
void	terminate(char *s);
void	control_colorscheme(int key, t_map *map);
int		mouse_move(int x, int y, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		mouse_press(int button, int x, int y, void *param);
int		key_press(int key, void *param);
int		key_release(int key, void *param);

#endif
