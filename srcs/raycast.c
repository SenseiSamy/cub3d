/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:28:21 by snaji             #+#    #+#             */
/*   Updated: 2023/07/18 18:16:31 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static t_image	*get_wall_text(t_raycast *r, t_world *world, char wall)
{
	double	angle;

	angle = atan2(r->raydir.y, r->raydir.x) * 180 / M_PI + 180;
	if (wall == '2')
		return (&world->door);
	if (r->side == 1)
	{
		if (angle < 180.0)
			return (&world->southwall);
		return (&world->northwall);
	}
	else
	{
		if (angle >= 90.0 && angle <= 270.0)
			return (&world->westwall);
		return (&world->eastwall);
	}
}

static void	texture(t_raycast *r, t_world *world, int x, char wall)
{
	int				color;
	int				y;
	const t_image	*tex = get_wall_text(r, world, wall);

	r->lineheight = (int)((double)WINDOW_H / r->perpwalldist);
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
	r->tex_x = (int)(r->wall_x * (double)tex->w);
	if (!(r->side == 0 && r->raydir.x > 0) && !(r->side == 1 && r->raydir.y < 0))
		r->tex_x = tex->w - r->tex_x - 1;
	r->step = 1.0 * tex->h / r->lineheight;
	r->tex_pos = (r->drawstart - WINDOW_H / 2 + r->lineheight / 2) * r->step;
	y = r->drawstart;
	while (y < r->drawend)
	{
		r->tex_y = (int)r->tex_pos & (tex->h - 1);
		r->tex_pos += r->step;
		color = get_pixel_from_img((t_image *)tex, r->tex_x, r->tex_y);
		put_pixel_to_img(&world->frame, x, y, color);
		++y;
	}
}

void	init_values(t_raycast *r, t_world *world, int x)
{
	r->camera_x = (2 * x / (double)WINDOW_W - 1) * -1;
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
			if (world->map[r.map_y][r.map_x] == '1'
				|| world->map[r.map_y][r.map_x] == '2')
				r.hit = 1;
		}
		if (r.side == 0)
			r.perpwalldist = r.sidedist.x - r.deltadist.x;
		else
			r.perpwalldist = r.sidedist.y - r.deltadist.y;
		r.perpwalldist *= cos(atan2(world->dir.y, world->dir.x)
			- atan2(r.raydir.y, r.raydir.x));
		texture(&r, world, x, world->map[r.map_y][r.map_x]);
		++x;
	}
	mlx_put_image_to_window(world->mlx, world->mlx_win, world->frame.img, 0, 0);
	return (EXIT_SUCCESS);
}
