/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:39:48 by snaji             #+#    #+#             */
/*   Updated: 2023/07/14 11:21:53 by wmari            ###   ########.fr       */
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

int	something_is_cooking(t_world *world)
{
	if (world->keys.escape || world->keys.up || world->keys.down || world->keys.left || world->keys.right || world->keys.larrow || world->keys.rarrow)
		return (0);
	return (1);
}

void print_map(t_world *world)
{
	int i, j;
	i = 0;
	while (world->map[i])
	{
		j = 0;
		while (world->map[i][j])
		{
			printf("%c", world->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	can_move_in_dir(t_world *world, int dir)
{
	if (dir == UP && world->map[(int)(world->pos.x + (0.03 * world->dir.x))][(int)(world->pos.y + (0.03 * world->dir.y))] != '1')
		return (print_map(world), 1);
	if (dir == DOWN && world->map[(int)(world->pos.x - (0.03 * world->dir.x))][(int)(world->pos.y - (0.03 * world->dir.y))] != '1')
		return (print_map(world), 1);
	if (dir == RIGHT && world->map[(int)(world->pos.x + (0.03 * world->plane.x))][(int)(world->pos.y + (0.03 * world->plane.y))] != '1')
		return (print_map(world), 1);
	if (dir == LEFT && world->map[(int)(world->pos.x - (0.03 * world->plane.x))][(int)(world->pos.y - (0.03 * world->plane.y))] != '1')
		return (print_map(world), 1);
	return (0);
}

int	hook_key_press(t_world *world)
{
	if (!something_is_cooking(world))
	{
		world->refresh = 1;
		if (world->keys.escape)
			exit_cub3d(world);
		if (world->keys.up && can_move_in_dir(world, UP))
		{
			world->pos.x += 0.03 * world->dir.x;
			world->pos.y += 0.03 * world->dir.y;
		}
		if (world->keys.down && can_move_in_dir(world, DOWN))
		{
			world->pos.x -= 0.03 * world->dir.x;
			world->pos.y -= 0.03 * world->dir.y;
		}
		if (world->keys.left && can_move_in_dir(world, LEFT))
		{
			world->pos.x -= 0.03 * world->plane.x;
			world->pos.y -= 0.03 * world->plane.y;
		}
		if (world->keys.right && can_move_in_dir(world, RIGHT))
		{
			world->pos.x += 0.03 * world->plane.x;
			world->pos.y += 0.03 * world->plane.y;
		}
		if (world->keys.rarrow)
			rotate_cam(world, -0.03);
		if (world->keys.larrow)
			rotate_cam(world, 0.03);
	}
	return (EXIT_SUCCESS);
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

void	set_hooks(t_world *world)
{
	mlx_hook(world->mlx_win, 2, 1L << 0, keypresses, world);
	mlx_hook(world->mlx_win, 3, 1L << 1, keyrelease, world);
	mlx_hook(world->mlx_win, 17, 0L, exit_cub3d, world);
}

int	main_loop(t_world *world)
{
	if (!something_is_cooking(world))
	{
		hook_key_press(world);
		raycast(world);
		world->refresh = 0;
	}
	return (EXIT_SUCCESS);
}
