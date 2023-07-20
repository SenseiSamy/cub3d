/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:45:42 by wmari             #+#    #+#             */
/*   Updated: 2023/07/20 15:41:27 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	coord_in_map(t_world *world, int x, int y)
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

	circle_radius = world->minimap.radius / 10;
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

void	color_circle(t_world *world, int xi, int yi)
{
	if (!coord_in_map(world, (int)(world->pos.x + (xi / 10)),
		(int)(world->pos.y + (yi / 10))))
		put_pixel_to_img(&world->frame, world->minimap.center_x + xi,
			world->minimap.center_y + yi, NAVY);
	else if (world->map[(int)(world->pos.y + (yi / 10))]
		[(int)(world->pos.x + (xi / 10))] == '1')
		put_pixel_to_img(&world->frame, world->minimap.center_x + xi,
			world->minimap.center_y + yi, VIOLET);
	else if (world->map[(int)(world->pos.y + (yi / 10))]
		[(int)(world->pos.x + (xi / 10))] == ' ')
		put_pixel_to_img(&world->frame, world->minimap.center_x + xi,
			world->minimap.center_y + yi, NAVY);
	else if (world->map[(int)(world->pos.y + (yi / 10))]
		[(int)(world->pos.x + (xi / 10))] == '2')
		put_pixel_to_img(&world->frame, world->minimap.center_x + xi,
			world->minimap.center_y + yi, GREY);
	else
		put_pixel_to_img(&world->frame, world->minimap.center_x + xi,
			world->minimap.center_y + yi, SILVER);
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
