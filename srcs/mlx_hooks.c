/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:39:48 by snaji             #+#    #+#             */
/*   Updated: 2023/07/13 15:06:53 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	rotate_cam(t_world *world, double value)
{
	double	tmp;

	tmp = world->dir.x;
	world->dir.x = world->dir.x * cos(value) - world->dir.y * sin(value);
	world->dir.y = tmp * sin(value) + world->dir.y * cos(value);
	tmp = world->plane.x;
	world->plane.x = world->plane.x * cos(value) - world->plane.y * sin(value);
	world->plane.y = tmp * sin(value) + world->plane.y * cos(value);
}

int	something_is_cooking(t_world *world)
{
	if (world->escape || world->up || world->down || world->left || world->right || world->larrow || world->rarrow)
		return (0);
	return (1);
}

int	hook_key_press(t_world *world)
{
	if (!something_is_cooking(world))
	{
		world->refresh = 1;
		if (world->escape)
			exit_cub3d(world);
		if (world->up)
		{
			world->pos.x += 0.03 * world->dir.x;
			world->pos.y += 0.03 * world->dir.y;
		}
		if (world->down)
		{
			world->pos.x -= 0.03 * world->dir.x;
			world->pos.y -= 0.03 * world->dir.y;
		}
		if (world->left)
		{
			world->pos.x -= 0.03 * world->plane.x;
			world->pos.y -= 0.03 * world->plane.y;
		}
		if (world->right)
		{
			world->pos.x += 0.03 * world->plane.x;
			world->pos.y += 0.03 * world->plane.y;
		}
		if (world->rarrow)
			rotate_cam(world, -0.006);
		if (world->larrow)
			rotate_cam(world, 0.006);
	}
	return (EXIT_SUCCESS);
}

int	keypresses(int keycode, t_world *world)
{
	if (keycode == W)
		world->up = 1;
	if (keycode == S)
		world->down = 1;
	if (keycode == A)
		world->left = 1;
	if (keycode == D)
		world->right = 1;
	if (keycode == L_ARROW)
		world->larrow = 1;
	if (keycode == R_ARROW)
		world->rarrow = 1;
	if (keycode == ESCAPE)
		world->escape = 1;
	return (hook_key_press(world));
}

int	keyrelease(int keycode, t_world *world)
{
	if (keycode == W)
		world->up = 0;
	if (keycode == S)
		world->down = 0;
	if (keycode == A)
		world->left = 0;
	if (keycode == D)
		world->right = 0;
	if (keycode == L_ARROW)
		world->larrow = 0;
	if (keycode == R_ARROW)
		world->rarrow = 0;
	if (keycode == ESCAPE)
		world->escape = 0;
	return (hook_key_press(world));
}

void	set_hooks(t_world *world)
{
	mlx_hook(world->mlx_win, 2, 1L << 0, keypresses, world);
	mlx_hook(world->mlx_win, 3, 1L << 1, keyrelease, world);
	mlx_hook(world->mlx_win, 17, 0L, exit_cub3d, world);
}
