/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:36:23 by snaji             #+#    #+#             */
/*   Updated: 2023/07/11 16:19:18 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_world(t_world *world)
{
	if (world->northwall.img)
		mlx_destroy_image(world->mlx, world->northwall.img);
	if (world->westwall.img)
		mlx_destroy_image(world->mlx, world->westwall.img);
	if (world->southwall.img)
		mlx_destroy_image(world->mlx, world->southwall.img);
	if (world->southwall.img)
		mlx_destroy_image(world->mlx, world->eastwall.img);
	if (world->frame.img)
		mlx_destroy_image(world->mlx, world->frame.img);
	if (world->map)
		ft_freearray((void **)world->map);
	if (world->mlx_win)
		mlx_destroy_window(world->mlx, world->mlx_win);
	if (world->mlx)
	{
		mlx_destroy_display(world->mlx);
		free(world->mlx);
	}
}

int	exit_cub3d(t_world *world)
{
	free_world(world);
	exit(EXIT_SUCCESS);
}