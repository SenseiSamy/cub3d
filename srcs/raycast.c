/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:28:21 by snaji             #+#    #+#             */
/*   Updated: 2023/07/10 22:13:04 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	init_values(t_raycast *r, t_world *world, int x)
{
	r->camera_x = 2 * x / (double)WINDOW_H - 1;
	r->raydir.x = world->dir.x + world->plane.x * r->camera_x;
	r->raydir.y = world->dir.y + world->plane.y * r->camera_x;
	r->map_x = (int)world->pos.x;
	r->map_y = (int)world->pos.y;
	r->deltadist.x = sqrt(1 + (r->raydir.y * r->raydir.y) / (r->raydir.x
		* r->raydir.x));
	r->deltadist.y = sqrt(1 + (r->raydir.x * r->raydir.x) / (r->raydir.y
		* r->raydir.y));
	r->hit = 0;
	if (r->raydir.x < 0)
	{
		r->step_x = -1;
		r->sidedist.x = (world->pos.x - r->map_x) * r->deltadist.x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist.x = (r->map_x + 1.0 - world->pos.x) * r->deltadist.x;
	}
	if (r->raydir.y < 0)
	{
		r->step_y = -1;
		r->sidedist.y = (world->pos.y - r->map_y) * r->deltadist.y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist.y = (r->map_y + 1.0 - world->pos.y) * r->deltadist.y;
	}
}

static void	texture(t_raycast *r, t_world *world, int x)
{
	int	color;
	int	y;

	r->lineheight = (int)(WINDOW_H / r->perpwalldist);
	r->drawstart = -r->lineheight / 2 + WINDOW_H / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineheight / 2 + WINDOW_H / 2;
	if (r->drawstart >= WINDOW_H)
		r->drawstart = WINDOW_H - 1;
	if (r->side == 0)
		r->wall_x = world->pos.y + r->perpwalldist * r->raydir.y;
	else
		r->wall_x = world->pos.x + r->perpwalldist * r->raydir.x;
	r->wall_x -= floor((r->wall_x));
	r->tex_x = (int)(r->wall_x * (double)world->northwall.h);
	if ((r->side == 0 && r->raydir.x > 0) || (r->side == 1 && r->raydir.x < 0))
		r->tex_x = world->northwall.h - r->tex_x - 1;
	r->step = 1.0 * world->northwall.h / r->lineheight;
	r->tex_pos = (r->drawstart - WINDOW_H / 2 + r->lineheight / 2) * r->step;
	y = r->drawstart;
	while (y < r->drawend)
	{
		r->tex_y = (int)r->tex_pos & (world->northwall.h - 1);
		r->tex_pos += r->step;
		color = get_pixel_from_img(&world->northwall, r->tex_x, r->tex_y);
		//maybe put darker color on sides here
		put_pixel_to_img(&world->frame, x, y, color);
		++y;
	}
}

int	raycast(t_world *world)
{
	t_raycast	r;
	int			x;

	ft_bzero(&r, sizeof (r));
	clear_image(world);
	x = 0;
	while (x < WINDOW_W)
	{
		init_values(&r, world, x);
		while (r.hit == 0)
		{
			if (r.sidedist.x < r.sidedist.y)
			{
				r.sidedist.x += r.deltadist.x;
				r.map_x += r.step_x;
				r.side = 0;
			}
			else
			{
				r.sidedist.y += r.deltadist.y;
				r.map_y += r.step_y;
				r.side = 1;
			}
			if (world->map[r.map_y][r.map_x] == '1')
				r.hit = 1;
		}
		if (r.side == 0)
			r.perpwalldist = (r.sidedist.x - r.deltadist.x);
		else
			r.perpwalldist = (r.sidedist.y - r.deltadist.y);
		texture(&r, world, x);
		++x;
	}
	mlx_put_image_to_window(world->mlx, world->mlx_win, world->frame.img, 0, 0);
	return (EXIT_SUCCESS);
}
