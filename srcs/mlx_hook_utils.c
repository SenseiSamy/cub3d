/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:51:36 by wmari             #+#    #+#             */
/*   Updated: 2023/07/15 16:16:48 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	keyrelease(int keycode, t_world *world)
{
	if (keycode == W)
		world->keys.up = 0;
	if (keycode == S)
		world->keys.down = 0;
	if (keycode == A)
		world->keys.left = 0;
	if (keycode == D)
		world->keys.right = 0;
	if (keycode == L_ARROW)
		world->keys.larrow = 0;
	if (keycode == R_ARROW)
		world->keys.rarrow = 0;
	if (keycode == ESCAPE)
		world->keys.escape = 0;
	return (hook_key_press(world));
}

int	keypresses(int keycode, t_world *world)
{
	if (keycode == W)
		world->keys.up = 1;
	if (keycode == S)
		world->keys.down = 1;
	if (keycode == A)
		world->keys.left = 1;
	if (keycode == D)
		world->keys.right = 1;
	if (keycode == L_ARROW)
		world->keys.larrow = 1;
	if (keycode == R_ARROW)
		world->keys.rarrow = 1;
	if (keycode == ESCAPE)
		world->keys.escape = 1;
	return (hook_key_press(world));
}

int	keys_is_not_pressed(t_world *world)
{
	if (world->keys.escape || world->keys.up || world->keys.down
		|| world->keys.left || world->keys.right || world->keys.larrow
		|| world->keys.rarrow)
		return (0);
	return (1);
}

int	can_move_in_dir(t_world *world, int dir)
{
	int	new_x;
	int	new_y;

	if (dir == UP)
	{
		new_x = (int)(world->pos.x + (0.03 * world->dir.x));
		new_y = (int)(world->pos.y + (0.03 * world->dir.y));
	}
	else if (dir == DOWN)
	{
		new_x = (int)(world->pos.x - (0.03 * world->dir.x));
		new_y = (int)(world->pos.y - (0.03 * world->dir.y));
	}
	else if (dir == RIGHT)
	{
		new_x = (int)(world->pos.x - (0.03 * world->plane.x));
		new_y = (int)(world->pos.y - (0.03 * world->plane.y));
	}
	else
	{
		new_x = (int)(world->pos.x + (0.03 * world->plane.x));
		new_y = (int)(world->pos.y + (0.03 * world->plane.y));
	}
	if (world->map[new_y] && world->map[new_y][new_x] == '1')
		return (0);
	return (1);
}
