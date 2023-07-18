/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:11:14 by snaji             #+#    #+#             */
/*   Updated: 2023/07/18 19:15:04 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_image	*get_wall_text(t_raycast *r, t_world *world, char wall)
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

static void inline	texture2(t_raycast *r, t_world *world, int x,
	const t_image *tex)
{
	int	y;

	r->tex_x = (int)(r->wall_x * (double)tex->w);
	if (!(r->side == 0 && r->raydir.x > 0)
		&& !(r->side == 1 && r->raydir.y < 0))
		r->tex_x = tex->w - r->tex_x - 1;
	r->step = 1.0 * tex->h / r->lineheight;
	r->tex_pos = (r->drawstart - WINDOW_H / 2 + r->lineheight / 2) * r->step;
	y = r->drawstart;
	while (y < r->drawend)
	{
		r->tex_y = (int)r->tex_pos & (tex->h - 1);
		r->tex_pos += r->step;
		put_pixel_to_img(&world->frame, x, y,
			get_pixel_from_img((t_image *)tex, r->tex_x, r->tex_y));
		++y;
	}
}

void	texture(t_raycast *r, t_world *world, int x, char wall)
{
	const t_image	*tex = get_wall_text(r, world, wall);

	if (r->side == 0)
		r->perpwalldist = r->sidedist.x - r->deltadist.x;
	else
		r->perpwalldist = r->sidedist.y - r->deltadist.y;
	r->perpwalldist *= cos(atan2(world->dir.y, world->dir.x)
			- atan2(r->raydir.y, r->raydir.x));
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
	texture2(r, world, x, tex);
}
