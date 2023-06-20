/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:28:37 by wmari             #+#    #+#             */
/*   Updated: 2023/06/20 15:08:49 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUBE3D_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>

#define NORTH	1
#define SOUTH	2
#define EAST	3
#define WEST	4

typedef struct	s_sprite
{
	char	*path_to_file;
	int		x;
	int		y;
}				t_sprite;

typedef struct	s_world
{
	void		*mlx;
	void		*mlx_win;
	t_sprite	northWall;
	t_sprite	southWall;
	t_sprite	eastWall;
	t_sprite	westWall;
	int			width;
	int			height;
}				t_world;

void	mlx_not_working(char *env);

/*GET_NEXT_LINE*/
int		get_next_line(int fd, char **line);
char	*fill_saved(int fd, char *saved, int *nbread, int buffer_size);
int		check_saved(char *saved);
char	*new_line(char *saved);
char	*clean_saved(char *saved);
char	*saved_append(char *saved, char *buf);
void	fill_with_save(char *nsaved, char *saved, char *buf);
void	fill_with_buf(char *nsaved, char *buf);
size_t	ft_strlen(const char *s);
char	*create_new_saved(char *saved, char *buf);

#endif