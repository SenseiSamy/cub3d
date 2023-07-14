/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:39:48 by snaji             #+#    #+#             */
/*   Updated: 2023/07/14 14:01:27 by wmari            ###   ########.fr       */
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

void	modif_position(t_world *world, int dir)
{
	if (dir == UP)
	{
		world->pos.x += 0.03 * world->dir.x;
		world->pos.y += 0.03 * world->dir.y;
	}
	if (dir == DOWN)
	{
		world->pos.x -= 0.03 * world->dir.x;
		world->pos.y -= 0.03 * world->dir.y;
	}
	if (dir == LEFT)
	{
		world->pos.x -= 0.03 * world->plane.x;
		world->pos.y -= 0.03 * world->plane.y;
	}
	if (dir == RIGHT)
	{
		world->pos.x += 0.03 * world->plane.x;
		world->pos.y += 0.03 * world->plane.y;
	}
}

int	hook_key_press(t_world *world)
{
	if (!keys_is_not_pressed(world))
	{
		world->refresh = 1;
		if (world->keys.escape)
			exit_cub3d(world);
		if (world->keys.up && can_move_in_dir(world, UP))
			modif_position(world, UP);
		if (world->keys.down && can_move_in_dir(world, DOWN))
			modif_position(world, DOWN);
		if (world->keys.left && can_move_in_dir(world, LEFT))
			modif_position(world, LEFT);
		if (world->keys.right && can_move_in_dir(world, RIGHT))
			modif_position(world, RIGHT);
		if (world->keys.rarrow)
			rotate_cam(world, -0.03);
		if (world->keys.larrow)
			rotate_cam(world, 0.03);
	}
	return (EXIT_SUCCESS);
}

void	set_hooks(t_world *world)
{
	mlx_hook(world->mlx_win, 2, 1L << 0, keypresses, world);
	mlx_hook(world->mlx_win, 3, 1L << 1, keyrelease, world);
	mlx_hook(world->mlx_win, 17, 0L, exit_cub3d, world);
}

int	main_loop(t_world *world)
{
	if (!keys_is_not_pressed(world))
	{
		hook_key_press(world);
		raycast(world);
		world->refresh = 0;
	}
	return (EXIT_SUCCESS);
}
