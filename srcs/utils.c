/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:36:23 by snaji             #+#    #+#             */
/*   Updated: 2023/08/23 10:58:13 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_circle(t_world *world)
{
	int	xi;
	int	yi;

	yi = -world->minimap.radius;
	while (yi <= world->minimap.radius)
	{
		xi = -world->minimap.radius;
		while (xi <= world->minimap.radius)
		{
			if (xi * xi + yi * yi <= world->minimap.radius
				* world->minimap.radius && xi * xi + yi * yi
				>= (world->minimap.radius * world->minimap.radius)
				- (10 * world->minimap.radius))
				put_pixel_to_img(&world->frame, world->minimap.center_x + xi,
					world->minimap.center_y + yi, BLACK);
			else if (xi * xi + yi * yi <= world->minimap.radius
				* world->minimap.radius)
				color_circle(world, xi, yi);
			xi++;
		}
		yi++;
	}
}

void	rotate_point(t_world *world, int *x, int *y)
{
	int		tmp;
	double	angle;

	tmp = *x;
	angle = (atan2(world->dir.y, world->dir.x) + (M_PI * 0.5));
	*x = (int)(*x * cos(angle) - *y * sin(angle));
	*y = (int)(tmp * sin(angle) + *y * cos(angle));
}

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
	if (world->mlx)
	{
		mlx_do_key_autorepeaton(world->mlx);
		mlx_mouse_show(world->mlx, world->mlx_win);
	}
	free_world(world);
	exit(EXIT_SUCCESS);
}
