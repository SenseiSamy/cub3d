/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:28:21 by snaji             #+#    #+#             */
/*   Updated: 2023/07/18 18:58:27 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	init_values2(t_raycast *r, t_world *world)
{
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

static void	init_values(t_raycast *r, t_world *world, int x)
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
	init_values2(r, world);
}

static inline void	dda(t_world *world, t_raycast *r)
{
	while (r->hit == 0)
	{
		if (r->sidedist.x < r->sidedist.y)
		{
			r->sidedist.x += r->deltadist.x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sidedist.y += r->deltadist.y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (world->map[r->map_y][r->map_x] == '1'
			|| world->map[r->map_y][r->map_x] == '2')
			r->hit = 1;
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
		dda(world, &r);
		texture(&r, world, x, world->map[r.map_y][r.map_x]);
		++x;
	}
	mlx_put_image_to_window(world->mlx, world->mlx_win, world->frame.img, 0, 0);
	return (EXIT_SUCCESS);
}
