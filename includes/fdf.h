/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:24:50 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:24:53 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include "/usr/local/include/mlx.h"
# include <math.h>
# include "../sources/gnl/get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define WIN_WIDTH	1000
# define WIN_HEIGHT	1000

/*fonts color*/
# define FBLACK		"\033[0;30m"
# define FRED		"\033[0;31m"
# define FGREEN		"\033[0;32m"
# define FYELLOW	"\033[0;33m"
# define FBLUE		 "\033[0;34m"
# define FPURPLE	"\033[0;35m"
# define FCYAN		"\x1b[36m"

/*end color*/
# define NONE        "\033[0m"

/*
addr - address of image;
void *imgage - the image instance;
int  bpp - will be filled with the number of bits 
needed to represent a pixel color (also called the depth of the image).;
int  size_line - number of bytes used to store one line of the image in memory;
int  endian - tells wether the pixel color in the image needs to be stored in:
little (endian == 0), or big (endian == 1);
*/
typedef struct image
{
	void	*image;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct map
{
	float	x0;
	float	x1;
	float	y0;
	float	y1;
	float	x_start;
	float	y_start;
	float	z0;
	float	z1;
	int		x;
	int		y;
	float	deltax;
	float	deltay;
	int		**z;
	void	*mlx_ptr;
	void	*win_ptr;
	int		distance;
	int		color;
	int		color0;
	int		color1;
	int		color1_std;
	int		color2_std;
	int		color3_std;
	int		**color_coord;
	float	angle;
	float	a;
	float	b;
	float	c;
	int		x_shift;
	int		y_shift;
	float	z_divisor;
	int		isometric;
	int		rotation;
	int		i;
	int		j;
	int		has_color;
	t_image	*img;
}	t_map;

void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *str);
int		ft_count_words(char const *line, char ch);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
void	free_arr(char **arr, int n);
int		ft_atoi_hex(const char *str);
int		ft_toupper(int c);
int		ft_is_digit_hex(char ch);

int		check_args(char *file, t_map *map_dots);

void	map_errors(int i, t_map *map_dots);
void	ft_errors(int i);

void	ft_free_map(t_map *map_dots);

void	ft_draw_line(t_map *map_dots);
void	ft_draw_map(t_map *map_dots);

void	ft_set_color(t_map *map_dots);
int		get_color(t_map *map_dots);
void	ft_define_color(t_map *map_dots);

void	ft_set_coord(t_map *map_dots);

void	ft_2d_rotation(t_map *map_dots);
int		ft_x_rotation(t_map *map_dots);
int		ft_y_rotation(t_map *map_dots);
int		ft_z_rotation(t_map *map_dots);

int		deal_key(int key, void *param);

void	ft_zoom(t_map *map_dots, int key);
void	ft_shift(t_map *map_dots, int key);
void	ft_iso(int key, t_map *map_dots);
void	ft_angle(t_map *map_dots, int key);
void	ft_change_color(t_map *map_dots, int key);

int		ft_close(void *param);

void	my_mlx_pixel_put(t_map *map_dots, int x, int y);

void	ft_init_image(t_map *map_dots);
void	ft_default_params(t_map *map_dots);
void	ft_map_init(t_map *map_dots);
void	ft_new_window(t_map *map_dots);

void	ft_draw_menu(t_map *map);

int		check_z_is_num(char *line, char **arr_words, \
	t_map *map_dots, char **arr_col);
int		check_col_is_num(char *line, char **arr_words, \
	t_map *map_dots, char **arr_col);
void	ft_map_is_not_rect(char *line, t_map *map_dots);
void	ft_help_func(char *line, char **arr_words, t_map *map_dots);

#endif
