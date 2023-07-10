/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:28:37 by wmari             #+#    #+#             */
/*   Updated: 2023/07/10 17:25:33 by snaji            ###   ########.fr       */
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

# define NORTH	1
# define SOUTH	2
# define EAST	3
# define WEST	4

# define ESCAPE 65307

typedef struct	s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct	s_sprite
{
	void	*sprite;
	int		x;
	int		y;
}				t_sprite;

typedef struct	s_world
{
	void		*mlx;
	void		*mlx_win;
	t_sprite	northwall;
	t_sprite	southwall;
	t_sprite	eastwall;
	t_sprite	westwall;
	int			floor_color;
	int			ceiling_color;
	int			width;
	int			height;
	char		**map;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}				t_world;

int			open_file(const char *file_name);
t_sprite	open_sprite(t_world *world, char *path);
int			get_color(char *str);
int			rgb(int r, int g, int b);
int			read_map(t_world *world, int fd, char *line);
bool		is_map(char *line);
int			verif_map(char **map);
int 		read_elem(t_world *world, int fd);
int			parse(t_world *world, char *file_name);
int			init_world(int argc, char **argv, t_world *world);
void		free_world(t_world *world);
void		set_hooks(t_world *world);
int			exit_cub3d(t_world *world);

#endif