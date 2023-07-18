/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:39:48 by snaji             #+#    #+#             */
/*   Updated: 2023/07/18 12:25:14 by wmari            ###   ########.fr       */
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

int		can_do_comp(t_world *world, int dir, int comp)
{
	int	new_x;
	int	new_y;
	
	if (dir == UP)
	{
		if (comp == X)
		{
			if (world->dir.x < 0.0)
				new_x = (int)(world->pos.x + (world->dir.x * MOVE) - OFF_WALL);
			else
				new_x = (int)(world->pos.x + (world->dir.x * MOVE) + OFF_WALL);
			new_y = (int)(world->pos.y);
			if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
				return (0);
			return (1);
		}
		else
		{
			new_x = (int)(world->pos.x);
			if (world->dir.y < 0.0)
				new_y = (int)(world->pos.y + (world->dir.y * MOVE) - OFF_WALL);
			else
				new_y = (int)(world->pos.y + (world->dir.y * MOVE) + OFF_WALL);
			if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
				return (0);
			return (1);
		}
	}
	if (dir == DOWN)
	{
		if (comp == X)
		{
			if (world->dir.x < 0.0)
				new_x = (int)(world->pos.x - (world->dir.x * MOVE) + OFF_WALL);
			else
				new_x = (int)(world->pos.x - (world->dir.x * MOVE) - OFF_WALL);
			new_y = (int)(world->pos.y);
			if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
				return (0);
			return (1);
		}
		else
		{
			new_x = (int)(world->pos.x);
			if (world->dir.y < 0.0)
				new_y = (int)(world->pos.y - (world->dir.y * MOVE) + OFF_WALL);
			else
				new_y = (int)(world->pos.y - (world->dir.y * MOVE) - OFF_WALL);
			if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
				return (0);
			return (1);
		}
	}
	if (dir == LEFT)
	{
		if (comp == X)
		{
			if (world->plane.x < 0.0)
				new_x = (int)(world->pos.x + (world->plane.x * MOVE) - OFF_WALL);
			else
				new_x = (int)(world->pos.x + (world->plane.x * MOVE) + OFF_WALL);
			new_y = (int)(world->pos.y);
			if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
				return (0);
			return (1);
		}
		else
		{
			new_x = (int)(world->pos.x);
			if (world->plane.y < 0.0)
				new_y = (int)(world->pos.y + (world->plane.y * MOVE) - OFF_WALL);
			else
				new_y = (int)(world->pos.y + (world->plane.y * MOVE) + OFF_WALL);
			if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
				return (0);
			return (1);
		}
	}
	if (dir == RIGHT)
	{
		if (comp == X)
		{
			if (world->plane.x < 0.0)
				new_x = (int)(world->pos.x - (world->plane.x * MOVE) + OFF_WALL);
			else
				new_x = (int)(world->pos.x - (world->plane.x * MOVE) - OFF_WALL);
			new_y = (int)(world->pos.y);
			if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
				return (0);
			return (1);
		}
		else
		{
			new_x = (int)(world->pos.x);
			if (world->plane.y < 0.0)
				new_y = (int)(world->pos.y - (world->plane.y * MOVE) + OFF_WALL);
			else
				new_y = (int)(world->pos.y - (world->plane.y * MOVE) - OFF_WALL);
			if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
				return (0);
			return (1);
		}
	}
	return (0);
}

void	modif_position(t_world *world, int dir)
{
	if (dir == UP)
	{
		if (can_do_comp(world, dir, X))
			world->pos.x += MOVE * world->dir.x;
		if (can_do_comp(world, dir, Y))
			world->pos.y += MOVE * world->dir.y;
	}
	if (dir == DOWN)
	{
		if (can_do_comp(world, dir, X))
			world->pos.x -= MOVE * world->dir.x;
		if (can_do_comp(world, dir, Y))
			world->pos.y -= MOVE * world->dir.y;
	}
	if (dir == LEFT)
	{
		if (can_do_comp(world, dir, X))
			world->pos.x += MOVE * world->plane.x;
		if (can_do_comp(world, dir, Y))
			world->pos.y += MOVE * world->plane.y;
	}
	if (dir == RIGHT)
	{
		if (can_do_comp(world, dir, X))
			world->pos.x -= MOVE * world->plane.x;
		if (can_do_comp(world, dir, Y))
			world->pos.y -= MOVE * world->plane.y;
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
			rotate_cam(world, MOVE);
		if (world->keys.larrow)
			rotate_cam(world, -MOVE);
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
		draw_circle(world);
		world->refresh = 0;
	}
	return (EXIT_SUCCESS);
}
