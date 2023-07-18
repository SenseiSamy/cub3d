/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:15:09 by snaji             #+#    #+#             */
/*   Updated: 2023/07/18 18:16:53 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "cub3D.h"

typedef struct	s_raycast
{
	double		camera_x;
	t_vector	raydir;
	int			map_x;
	int			map_y;
	t_vector	sidedist;
	t_vector	deltadist;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}			t_raycast;

t_image	*get_wall_text(t_raycast *r, t_world *world, char wall);

#endif