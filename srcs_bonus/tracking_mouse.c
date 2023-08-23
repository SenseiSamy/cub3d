/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracking_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:44:41 by wmari             #+#    #+#             */
/*   Updated: 2023/08/23 11:26:47 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_changing_pos(int x, int y, t_world *world)
{
	world->mouse.x = x;
	world->mouse.y = y;
	return (0);
}

int	tracking_mouse(t_world *world)
{
	if (world->focus == 0)
	{
		if (world->mouse.x < WINDOW_W * 0.5)
		{
			while (world->mouse.x++ < WINDOW_W * 0.5)
				rotate_cam(world, -(MOVE * world->frametime) * MOUSE_SENSI);
		}
		else
		{
			while (world->mouse.x-- > WINDOW_W * 0.5)
				rotate_cam(world, (MOVE * world->frametime) * MOUSE_SENSI);
		}
		world->mouse.x = WINDOW_W * 0.5;
		mlx_mouse_move(world->mlx, world->mlx_win,
			WINDOW_W * 0.5, WINDOW_H * 0.5);
	}
	return (0);
}
