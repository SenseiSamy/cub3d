/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:39:48 by snaji             #+#    #+#             */
/*   Updated: 2023/08/22 17:20:10 by snaji            ###   ########.fr       */
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
			rotate_cam(world, CAM_SPEED);
		if (world->keys.larrow)
			rotate_cam(world, -CAM_SPEED);
	}
	return (EXIT_SUCCESS);
}

int	change_focus(t_world *world)
{
	world->focus = (world->focus + 1) % 2;
	if (world->focus == 0)
	{
		mlx_mouse_move(world->mlx, world->mlx_win, WINDOW_W / 2, WINDOW_H / 2);
		mlx_hook(world->mlx_win, MotionNotify, PointerMotionMask,
			mouse_changing_pos, world);
	}
	else
		mlx_hook(world->mlx_win, MotionNotify, 0, NULL, NULL);
	return (0);
}

void	set_hooks(t_world *world)
{
	mlx_hook(world->mlx_win, KeyPress, KeyPressMask, keypresses, world);
	mlx_hook(world->mlx_win, KeyRelease, KeyReleaseMask, keyrelease, world);
	mlx_hook(world->mlx_win, DestroyNotify, NoEventMask, exit_cub3d, world);
	mlx_hook(world->mlx_win, MotionNotify, PointerMotionMask,
		mouse_changing_pos, world);
	mlx_hook(world->mlx_win, FocusIn, FocusChangeMask, change_focus, world);
	mlx_hook(world->mlx_win, FocusOut, FocusChangeMask, change_focus, world);
}

int	main_loop(t_world *world)
{
	world->frametime = time_passed(world, world->lastframe) / 1000000.0;
	if (gettimeofday(&world->lastframe, NULL) == -1)
		exit_cub3d(world);
	hook_key_press(world);
	tracking_mouse(world);
	raycast(world);
	draw_minimap(world);
	return (EXIT_SUCCESS);
}
