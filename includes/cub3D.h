/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:28:37 by wmari             #+#    #+#             */
/*   Updated: 2023/07/10 21:48:41 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "mlx_int.h"
# include <math.h>
# include "libft.h"
# include <stdbool.h>
# include <errno.h>

# define WINDOW_W 1280
# define WINDOW_H 720

# define ESCAPE 65307
# define W 119
# define S 115
# define A 97
# define D 100

typedef struct	s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_image;

typedef struct	s_world
{
	void		*mlx;
	void		*mlx_win;
	t_image		northwall;
	t_image		southwall;
	t_image		eastwall;
	t_image		westwall;
	int			floor_color;
	int			ceiling_color;
	int			width;
	int			height;
	char		**map;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_image		frame;
}				t_world;

int		open_file(const char *file_name);
t_image	open_sprite(t_world *world, char *path);
int		get_color(char *str);
int		rgb(int r, int g, int b);
int		read_map(t_world *world, int fd, char *line);
bool	is_map(char *line);
int		verif_map(char **map);
int 	read_elem(t_world *world, int fd);
int		parse(t_world *world, char *file_name);
int		init_world(int argc, char **argv, t_world *world);
void	free_world(t_world *world);
void	set_hooks(t_world *world);
int		exit_cub3d(t_world *world);

void	put_pixel_to_img(t_image *img, int x, int y, int color);
int		get_pixel_from_img(t_image *img, int x, int y);
void	clear_image(t_world *world);

int		raycast(t_world *world);

#endif