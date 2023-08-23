/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:43:13 by wmari             #+#    #+#             */
/*   Updated: 2023/08/23 11:25:21 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	comp_up(t_world *world, int comp, int new_x, int new_y)
{
	const double	move = MOVE * world->frametime;

	if (comp == X)
	{
		if (world->dir.x < 0.0)
			new_x = (int)(world->pos.x + (world->dir.x * move) - OFF_WALL);
		else
			new_x = (int)(world->pos.x + (world->dir.x * move) + OFF_WALL);
		new_y = (int)(world->pos.y);
		if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
			return (0);
		return (1);
	}
	else
	{
		new_x = (int)(world->pos.x);
		if (world->dir.y < 0.0)
			new_y = (int)(world->pos.y + (world->dir.y * move) - OFF_WALL);
		else
			new_y = (int)(world->pos.y + (world->dir.y * move) + OFF_WALL);
		if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
			return (0);
		return (1);
	}
}

static int	comp_down(t_world *world, int comp, int new_x, int new_y)
{
	const double	move = MOVE * world->frametime;

	if (comp == X)
	{
		if (world->dir.x < 0.0)
			new_x = (int)(world->pos.x - (world->dir.x * move) + OFF_WALL);
		else
			new_x = (int)(world->pos.x - (world->dir.x * move) - OFF_WALL);
		new_y = (int)(world->pos.y);
		if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
			return (0);
		return (1);
	}
	else
	{
		new_x = (int)(world->pos.x);
		if (world->dir.y < 0.0)
			new_y = (int)(world->pos.y - (world->dir.y * move) + OFF_WALL);
		else
			new_y = (int)(world->pos.y - (world->dir.y * move) - OFF_WALL);
		if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
			return (0);
		return (1);
	}
}

static int	comp_left(t_world *world, int comp, int new_x, int new_y)
{
	const double	move = MOVE * world->frametime;

	if (comp == X)
	{
		if (world->plane.x < 0.0)
			new_x = (int)(world->pos.x + (world->plane.x * move) - OFF_WALL);
		else
			new_x = (int)(world->pos.x + (world->plane.x * move) + OFF_WALL);
		new_y = (int)(world->pos.y);
		if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
			return (0);
		return (1);
	}
	else
	{
		new_x = (int)(world->pos.x);
		if (world->plane.y < 0.0)
			new_y = (int)(world->pos.y + (world->plane.y * move) - OFF_WALL);
		else
			new_y = (int)(world->pos.y + (world->plane.y * move) + OFF_WALL);
		if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
			return (0);
		return (1);
	}
}

static int	comp_right(t_world *world, int comp, int new_x, int new_y)
{
	const double	move = MOVE * world->frametime;

	if (comp == X)
	{
		if (world->plane.x < 0.0)
			new_x = (int)(world->pos.x - (world->plane.x * move) + OFF_WALL);
		else
			new_x = (int)(world->pos.x - (world->plane.x * move) - OFF_WALL);
		new_y = (int)(world->pos.y);
		if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
			return (0);
		return (1);
	}
	else
	{
		new_x = (int)(world->pos.x);
		if (world->plane.y < 0.0)
			new_y = (int)(world->pos.y - (world->plane.y * move) + OFF_WALL);
		else
			new_y = (int)(world->pos.y - (world->plane.y * move) - OFF_WALL);
		if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x] == '2')
			return (0);
		return (1);
	}
}

int	can_do_comp(t_world *world, int dir, int comp)
{
	int	new_x;
	int	new_y;

	new_x = 0;
	new_y = 0;
	if (dir == UP)
		return (comp_up(world, comp, new_x, new_y));
	if (dir == DOWN)
		return (comp_down(world, comp, new_x, new_y));
	if (dir == LEFT)
		return (comp_left(world, comp, new_x, new_y));
	if (dir == RIGHT)
		return (comp_right(world, comp, new_x, new_y));
	return (0);
}
