/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracking_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:44:41 by wmari             #+#    #+#             */
/*   Updated: 2023/07/21 14:14:29 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	tracking_mouse(t_world *world)
{
	int	new_x;
	int	new_y;

	mlx_mouse_get_pos(world->mlx, world->mlx_win, &new_x, &new_y);
	if (new_x < world->mouse.x)
	{
		while (new_x++ < world->mouse.x)
			rotate_cam(world, -MOVE * MOUSE_SENSI);

	}
	else
	{
		while (new_x-- > world->mouse.x)
			rotate_cam(world, MOVE * MOUSE_SENSI);
	}
	mlx_mouse_move(world->mlx, world->mlx_win, WINDOW_W / 2, WINDOW_H / 2);
	return (0);
}