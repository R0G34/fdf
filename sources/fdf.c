/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:41:18 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/15 12:12:34 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argv != 2)
		terminate(ARGC_ERR);
	load_map(&fdf.map, argv[1]);
	fdf.win.mlx = mlx_init();
	fdf.win.win = mlx_new_window(fdf.win.mlx, WINX, WINY, \
	"abausa-v");
	fdf.img.image = mlx_new_image(fdf.win.mlx, WINX, WINY);
	fdf.img.addr = mlx_get_ata_addr(fdf.img.image, \
		&fdf.img.bitxpixel, &fdf.img.lines, &fdf.img.endian);
	if (draw_map(&fdf, FIT) < 0)
		terminate(MAP_ERR);
	mlx_hook(fdf.win.win, 2, 0, key_press, &fdf);
	mlx_hook(fdf.win.win, 3, 0, key_release, &fdf);
	mlx_hook(fdf.win.win, 4, 0, mouse_press, &fdf);
	mlx_hook(fdf.win.win, 5, 0, mouse_release, &fdf);
	mlx_hook(fdf.win.win, 6, 0, mouse_move, &fdf);
	mlx_hook(fdf.win.win, 17, 0, terminate_program, &fdf);
	mlx_loop(fdf.win.mlx);
	free (fdf.map.points);
	free (fdf.map.memory);
	return (0);
}
