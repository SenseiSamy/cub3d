/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:39:48 by snaji             #+#    #+#             */
/*   Updated: 2023/08/19 19:29:15 by snaji            ###   ########.fr       */
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

int	hook_key_press(t_world *world)
{
	if (!keys_is_not_pressed(world))
	{
		if (world->keys.escape)
			exit_cub3d(world);
		if (world->keys.up)
			modif_position(world, UP);
		if (world->keys.down)
			modif_position(world, DOWN);
		if (world->keys.left)
			modif_position(world, LEFT);
		if (world->keys.right)
			modif_position(world, RIGHT);
		if (world->keys.rarrow)
			rotate_cam(world, MOVE);
		if (world->keys.larrow)
			rotate_cam(world, -MOVE);
	}
	return (EXIT_SUCCESS);
}

void	set_hooks(t_world *world)
{
	mlx_hook(world->mlx_win, KeyPress, KeyPressMask, keypresses, world);
	mlx_hook(world->mlx_win, KeyRelease, KeyReleaseMask, keyrelease, world);
	mlx_hook(world->mlx_win, DestroyNotify, NoEventMask, exit_cub3d, world);
}

int	main_loop(t_world *world)
{
	hook_key_press(world);
	raycast(world);
	return (EXIT_SUCCESS);
}
