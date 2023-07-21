/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:28:37 by wmari             #+#    #+#             */
/*   Updated: 2023/07/21 18:37:19 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include <stdbool.h>
# include <errno.h>

# define WINDOW_W 1280
# define WINDOW_H 720

# ifndef __APPLE__
#  define ESCAPE 65307
#  define W 119
#  define S 115
#  define A 97
#  define D 100
#  define E 101
#  define R_ARROW 65363
#  define L_ARROW 65361
# else
#  define ESCAPE 53
#  define W 13
#  define S 1
#  define A 0
#  define D 2
#  define R_ARROW 124
#  define L_ARROW 123
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define MOVE 0.03
# define OFF_WALL 0.3
# define MINIMAP_ZOOM 0.1
# define MOUSE_SENSI 0.1

# define GREY 0x00808080
# define BLACK 0x00191919
# define VIOLET 0x007F00FF
# define SILVER 0x00C0C0C0
# define NAVY 0x00000080

enum e_direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum e_comp {
	X,
	Y
};

typedef struct s_keyboard
{
	int	up;
	int	down;
	int	right;
	int	left;
	int	use;
	int	larrow;
	int	rarrow;
	int	escape;
}				t_keyboard;

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_image;

typedef struct s_minimap
{
	int	center_x;
	int	center_y;
	int	radius;
}				t_minimap;

typedef struct s_mouse
{
	int	x;
	int	y;
}				t_mouse;

typedef struct s_world
{
	void		*mlx;
	void		*mlx_win;
	t_image		northwall;
	t_image		southwall;
	t_image		eastwall;
	t_image		westwall;
	t_image		door;
	int			floor_color;
	int			ceiling_color;
	int			width;
	int			height;
	char		**map;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_image		frame;
	t_keyboard	keys;
	int			refresh;
	t_minimap	minimap;
	t_mouse		mouse;
	int			focus;
}				t_world;

int		open_file(const char *file_name);
t_image	open_sprite(t_world *world, char *path);
int		get_color(char *str);
int		rgb(int r, int g, int b);
int		read_map(t_world *world, int fd, char *line);
bool	is_map(char *line);
int		verif_map(char **map);
int		get_start_pos(char **map, int *x, int *y);
int		read_elem(t_world *world, int fd);
int		parse(t_world *world, char *file_name);
int		init_world(int argc, char **argv, t_world *world);
void	free_world(t_world *world);
int		exit_cub3d(t_world *world);
void	rotate_cam(t_world *world, double value);

void	put_pixel_to_img(t_image *img, int x, int y, int color);
int		get_pixel_from_img(t_image *img, int x, int y);
void	clear_image(t_world *world);

int		raycast(t_world *world);
/*_________________MLX_HOOKS________________*/
int		main_loop(t_world *world);
void	set_hooks(t_world *world);
int		hook_key_press(t_world *world);
int		keyrelease(int keycode, t_world *world);
int		keypresses(int keycode, t_world *world);
int		keys_is_not_pressed(t_world *world);
int		can_move_in_dir(t_world *world, int dir);
void	modif_position(t_world *world, int dir);
void	rotate_cam(t_world *world, double value);
void	door_use(t_world *world);
int		can_do_comp(t_world *world, int dir, int comp);
void	draw_minimap(t_world *world);
int		tracking_mouse(t_world *world);
int		mouse_changing_pos(int x, int y, t_world *world);
#endif