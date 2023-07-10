/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:39:48 by snaji             #+#    #+#             */
/*   Updated: 2023/07/10 22:12:18 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	hook_key_press(int key, t_world *world)
{
	if (key == ESCAPE)
		exit_cub3d(world);
	else if (key == W)
		world->pos.x -= 0.1;
	else if (key == S)
		world->pos.x += 0.1;
	else if (key == A)
		world->pos.y -= 0.1;
	else if (key == D)
		world->pos.y += 0.1;
	else
		return (EXIT_SUCCESS);
	raycast(world);
	return (EXIT_SUCCESS);
}

void	set_hooks(t_world *world)
{
	mlx_hook(world->mlx_win, 2, 1L << 0, hook_key_press, world);
	mlx_hook(world->mlx_win, 17, 0L, exit_cub3d, world);
}
