/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:36:23 by snaji             #+#    #+#             */
/*   Updated: 2023/08/14 16:37:18 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	time_passed(t_world *world, struct timeval time)
{
	size_t			time_ms;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		exit_cub3d(world);
	time_ms = (current_time.tv_sec * 1000000 + current_time.tv_usec)
		- (time.tv_sec * 1000000 + time.tv_usec);
	return (time_ms);
}

void	free_world(t_world *world)
{
	free_texture(world, &world->northwall);
	free_texture(world, &world->westwall);
	free_texture(world, &world->southwall);
	free_texture(world, &world->eastwall);
	free_texture(world, &world->door);
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
	ft_bzero(world, sizeof (*world));
}

int	exit_cub3d(t_world *world)
{
	mlx_do_key_autorepeaton(world->mlx);
	mlx_mouse_show(world->mlx, world->mlx_win);
	free_world(world);
	exit(EXIT_SUCCESS);
}
