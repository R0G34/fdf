/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:21:51 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:26:46 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

void	map_errors(int i, t_map *map_dots)
{
	if (i == 1)
		ft_putstr_fd(FRED"Invalid map: z coord should be integer.\n"NONE, 1);
	else if (i == 2)
		ft_putstr_fd(FRED"Invalid map: map should be rectangular.\n"NONE, 1);
	else if (i == 3)
		ft_putstr_fd(FRED"Invalid map: wrong color coord.\n"NONE, 1);
	ft_free_map(map_dots);
	exit(1);
}

void	ft_errors(int i)
{
	if (i == 3)
		ft_putstr_fd(FRED"Wrong number of args.\nUsage: ./fdf [file]"NONE, 1);
	else if (i == 4)
		ft_putstr_fd(FRED"Can not open the file.\n"NONE, 1);
	else if (i == 5)
		ft_putstr_fd(FRED"Can not close the file.\n"NONE, 1);
	else if (i == 6)
		ft_putstr_fd(FRED"Memory wasn't allocated.\n"NONE, 1);
	exit(EXIT_FAILURE);
}
