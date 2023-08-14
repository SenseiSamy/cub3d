/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:45:42 by wmari             #+#    #+#             */
/*   Updated: 2023/08/14 17:36:00 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	coord_in_map(t_world *world, int x, int y)
{
	int	dx;
	int	dy;

	if (x < 0 || y < 0)
		return (0);
	dy = 0;
	while (world->map[dy] && dy < y)
		dy++;
	if (!world->map[dy])
		return (0);
	dx = 0;
	while (world->map[dy][dx] && dx < x)
		dx++;
	if (!world->map[dy][dx])
		return (0);
	return (1);
}

static void	draw_player(t_world *world)
{
	int	circle_radius;
	int	xi;
	int	yi;

	circle_radius = world->minimap.radius * MINIMAP_ZOOM * 0.8;
	yi = -circle_radius;
	while (yi <= circle_radius)
	{
		xi = -circle_radius;
		while (xi <= circle_radius)
		{
			if (xi * xi + yi * yi <= circle_radius * circle_radius)
				put_pixel_to_img(&world->frame, world->minimap.center_x + xi,
					world->minimap.center_y + yi, BLACK);
			xi++;
		}
		yi++;
	}
}

static void	rotate_point(t_world *world, int *x, int *y)
{
	int		tmp;
	double	angle;

	tmp = *x;
	angle = -(atan2(world->dir.y, world->dir.x) + M_PI / 2);
	*x = (int)(*x * cos(angle) - *y * sin(angle));
	*y = (int)(tmp * sin(angle) + *y * cos(angle));
}

static void	color_circle(t_world *world, int xi, int yi)
{
	int	rotated_x;
	int	rotated_y;

	rotated_x = xi;
	rotated_y = yi;
	rotate_point(world, &rotated_x, &rotated_y);
	if (!coord_in_map(world, (int)(world->pos.x + (xi * MINIMAP_ZOOM)),
		(int)(world->pos.y + (yi * MINIMAP_ZOOM))))
		put_pixel_to_img(&world->frame, world->minimap.center_x + rotated_x,
			world->minimap.center_y + rotated_y, NAVY);
	else if (world->map[(int)(world->pos.y + (yi * MINIMAP_ZOOM))]
		[(int)(world->pos.x + (xi * MINIMAP_ZOOM))] == '1')
		put_pixel_to_img(&world->frame, world->minimap.center_x + rotated_x,
			world->minimap.center_y + rotated_y, VIOLET);
	else if (world->map[(int)(world->pos.y + (yi * MINIMAP_ZOOM))]
		[(int)(world->pos.x + (xi * MINIMAP_ZOOM))] == ' ')
		put_pixel_to_img(&world->frame, world->minimap.center_x + rotated_x,
			world->minimap.center_y + rotated_y, NAVY);
	else if (world->map[(int)(world->pos.y + (yi * MINIMAP_ZOOM))]
		[(int)(world->pos.x + (xi * MINIMAP_ZOOM))] == '2')
		put_pixel_to_img(&world->frame, world->minimap.center_x + rotated_x,
			world->minimap.center_y + rotated_y, GREY);
	else
		put_pixel_to_img(&world->frame, world->minimap.center_x + rotated_x,
			world->minimap.center_y + rotated_y, SILVER);
}

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

void	draw_minimap(t_world *world)
{
	draw_circle(world);
	draw_player(world);
}
