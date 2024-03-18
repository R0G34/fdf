/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:22:07 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:27:31 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"
#include "../includes/colors.h"
#include "../includes/key.h"

int	ft_close(void *param)
{
	t_map	*map_dots;

	map_dots = param;
	mlx_destroy_window(map_dots->mlx_ptr, map_dots->win_ptr);
	exit(0);
	return (0);
}

/*
 1) Check num of args
 2) Open the file
 3) Read data from the file - array or list?
 4) Check validity
 */
int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map_dots;

	if (argc != 2)
		ft_errors(3);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		ft_errors(4);
	if (close(fd) == -1)
		ft_errors(5);
	map_dots = malloc(sizeof(t_map));
	if (!map_dots)
		ft_errors(6);
	check_args(argv[1], map_dots);
	ft_new_window(map_dots);
	ft_free_map(map_dots);
	return (0);
}
