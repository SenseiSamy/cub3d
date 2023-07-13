/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:39:48 by snaji             #+#    #+#             */
/*   Updated: 2023/07/13 14:54:19 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_cam(t_world *world, double value)
{
	double	tmp;

	tmp = world->dir.x;
	world->dir.x = world->dir.x * cos(value) - world->dir.y * sin(value);
	world->dir.y = tmp * sin(value) + world->dir.y * cos(value);
	tmp = world->plane.x;
	world->plane.x = world->plane.x * cos(value) - world->plane.y * sin(value);
	world->plane.y = tmp * sin(value) + world->plane.y * cos(value);
}

static int	hook_key_press(int key, t_world *world)
{
	if (key == ESCAPE)
		exit_cub3d(world);
	else if (key == W)
	{
		world->pos.x += 0.1 * world->dir.x;
		world->pos.y += 0.1 * world->dir.y;
	}
	else if (key == S)
	{
		world->pos.x -= 0.1 * world->dir.x;
		world->pos.y -= 0.1 * world->dir.y;
	}
	else if (key == A)
	{
		world->pos.x -= 0.1 * world->plane.x;
		world->pos.y -= 0.1 * world->plane.y;
	}
	else if (key == D)
	{
		world->pos.x += 0.1 * world->plane.x;
		world->pos.y += 0.1 * world->plane.y;
	}
	else if (key == R_ARROW)
		rotate_cam(world, -M_PI / 50);
	else if (key == L_ARROW)
		rotate_cam(world, M_PI / 50);
	else
		return (EXIT_SUCCESS);
	raycast(world);
	return (EXIT_SUCCESS);
}

void	set_hooks(t_world *world)
{
	mlx_hook(world->mlx_win, 2, 1L << 0, hook_key_press, world);
	mlx_hook(world->mlx_win, 17, 0L, exit_cub3d, world);
}
