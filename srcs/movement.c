/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:53:57 by wmari             #+#    #+#             */
/*   Updated: 2023/07/20 12:01:20 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	move_up(t_world *world)
{
	if (can_do_comp(world, UP, X))
		world->pos.x += MOVE * world->dir.x;
	if (can_do_comp(world, UP, Y))
		world->pos.y += MOVE * world->dir.y;
}

static void	move_down(t_world *world)
{
	if (can_do_comp(world, DOWN, X))
		world->pos.x -= MOVE * world->dir.x;
	if (can_do_comp(world, DOWN, Y))
		world->pos.y -= MOVE * world->dir.y;
}

static void	move_left(t_world *world)
{
	if (can_do_comp(world, LEFT, X))
		world->pos.x += MOVE * world->plane.x;
	if (can_do_comp(world, LEFT, Y))
		world->pos.y += MOVE * world->plane.y;
}

static void	move_right(t_world *world)
{
	if (can_do_comp(world, RIGHT, X))
		world->pos.x -= MOVE * world->plane.x;
	if (can_do_comp(world, RIGHT, Y))
		world->pos.y -= MOVE * world->plane.y;
}

void	modif_position(t_world *world, int dir)
{
	if (dir == UP)
		move_up(world);
	if (dir == DOWN)
		move_down(world);
	if (dir == LEFT)
		move_left(world);
	if (dir == RIGHT)
		move_right(world);
}
