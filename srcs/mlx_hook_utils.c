/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:51:36 by wmari             #+#    #+#             */
/*   Updated: 2023/07/17 13:43:24 by wmari            ###   ########.fr       */
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
	if (keycode == E)
		world->keys.use = 0;
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
	if (keycode == E)
	{
		door_use(world);
		world->keys.use = 1;
	}
	return (hook_key_press(world));
}

int	keys_is_not_pressed(t_world *world)
{
	if (world->keys.escape || world->keys.up || world->keys.down
		|| world->keys.left || world->keys.right || world->keys.larrow
		|| world->keys.rarrow || world->keys.use)
		return (0);
	return (1);
}

int	too_close_of_wall(t_world *world, int dir)
{
	if (dir == UP)
	{
		if (world->map[(int)(world->pos.y + (MOVE * world->dir.y) + 1.5)][(int)(world->pos.x + (MOVE * world->dir.x) + 1.5)] != '0')
			return (0);
		return (printf("map[%lf][%lf] = %c\nplayer pos[%lf][%lf]\n",(world->pos.y + (MOVE * world->dir.y) + 1.5), (world->pos.x + (MOVE * world->dir.x) + 1.5), world->map[(int)(world->pos.y + (MOVE * world->dir.y) + 1.5)][(int)(world->pos.x + (MOVE * world->dir.x) + 1.5)], world->pos.y, world->pos.x), 1);
	}
	if (dir == DOWN)
	{
		if (world->map[(int)(world->pos.y - (MOVE * world->dir.y) - 1.5)][(int)(world->pos.x - (MOVE * world->dir.x) - 1.5)] != '0')
			return (0);
		return (printf("map[%lf][%lf] = %c\nplayer pos[%lf][%lf]\n",(world->pos.y + (MOVE * world->dir.y) + 1.5), (world->pos.x + (MOVE * world->dir.x) + 1.5), world->map[(int)(world->pos.y + (MOVE * world->dir.y) + 1.5)][(int)(world->pos.x + (MOVE * world->dir.x) + 1.5)], world->pos.y, world->pos.x), 1);

	}
	if (dir == RIGHT)
	{
		if (world->map[(int)(world->pos.y + (MOVE * world->plane.y) + 1.5)][(int)(world->pos.x + (MOVE * world->plane.x) + 1.5)] != '0')
			return (0);
		return (printf("map[%lf][%lf] = %c\nplayer pos[%lf][%lf]\n",(world->pos.y + (MOVE * world->dir.y) + 1.5), (world->pos.x + (MOVE * world->dir.x) + 1.5), world->map[(int)(world->pos.y + (MOVE * world->dir.y) + 1.5)][(int)(world->pos.x + (MOVE * world->dir.x) + 1.5)], world->pos.y, world->pos.x), 1);
	}
	if (dir == LEFT)
	{
		if (world->map[(int)(world->pos.y - (MOVE * world->plane.y) - 1.5)][(int)(world->pos.x - (MOVE * world->plane.x) - 1.5)] != '0')
			return (0);
		return (printf("map[%lf][%lf] = %c\nplayer pos[%lf][%lf]\n",(world->pos.y + (MOVE * world->dir.y) + 1.5), (world->pos.x + (MOVE * world->dir.x) + 1.5), world->map[(int)(world->pos.y + (MOVE * world->dir.y) + 1.5)][(int)(world->pos.x + (MOVE * world->dir.x) + 0.3)], world->pos.y, world->pos.x), 1);
	}
	return (0);
}

int	can_move_in_dir(t_world *world, int dir)
{
	int	new_x;
	int	new_y;

	if (dir == UP && too_close_of_wall(world, dir))
	{
		new_x = (int)(world->pos.x + (MOVE * world->dir.x));
		new_y = (int)(world->pos.y + (MOVE * world->dir.y));
	}
	else if (dir == DOWN && too_close_of_wall(world, dir))
	{
		new_x = (int)(world->pos.x - (MOVE * world->dir.x));
		new_y = (int)(world->pos.y - (MOVE * world->dir.y));
	}
	else if (dir == RIGHT && too_close_of_wall(world, dir))
	{
		new_x = (int)(world->pos.x - (MOVE * world->plane.x));
		new_y = (int)(world->pos.y - (MOVE * world->plane.y));
	}
	else if (dir == LEFT && too_close_of_wall(world, dir))
	{
		new_x = (int)(world->pos.x + (MOVE * world->plane.x));
		new_y = (int)(world->pos.y + (MOVE * world->plane.y));
	}
	else
	{
		new_x = (int)(world->pos.x);
		new_y = (int)(world->pos.y);
	}
	if (world->map[new_y] && (world->map[new_y][new_x] == '1'
		|| world->map[new_y][new_x] == '2'))
		return (0);
	return (1);
}

void	door_use(t_world *world)
{
	int	mapx;
	int	mapy;

	mapx = (int)(world->pos.x + world->dir.x);
	mapy = (int)(world->pos.y + world->dir.y);
	if (world->map[mapy][mapx] == '2')
		world->map[mapy][mapx] = '3';
	else if (world->map[mapy][mapx] == '3')
		world->map[mapy][mapx] = '2';
}