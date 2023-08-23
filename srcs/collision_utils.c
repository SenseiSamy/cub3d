/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:59:11 by wmari             #+#    #+#             */
/*   Updated: 2023/08/23 12:16:19 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	can_do_move(t_world *world, int x, int y, int comp)
{
	int	new_x;
	int	new_y;

	if (comp == X)
	{
		new_y = (int)(world->pos.y + OFF_WALL); 
		if (world->map[new_y][x] == '1' || world->map[new_y][x] == '2')
			return (0);
		new_y = (int)(world->pos.y - OFF_WALL);
		if (world->map[new_y][x] == '1' || world->map[new_y][x] == '2')
			return (0);
		return (1);
	}
	else
	{
		new_x = (int)(world->pos.x + OFF_WALL);
		if (world->map[y][new_x] == '1' || world->map[y][new_x] == '2')
			return (0);
		new_x = (int)(world->pos.x - OFF_WALL);
		if (world->map[y][new_x] == '1' || world->map[y][new_x] == '2')
			return (0);
		return (1);
	}
}