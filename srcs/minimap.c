/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:45:42 by wmari             #+#    #+#             */
/*   Updated: 2023/07/18 18:00:44 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		coord_in_map(t_world *world, int x, int y)
{
	int dx;
	int dy;

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

void	draw_circle(t_world *world)
{
	int radius;
	int	center_x;
	int	center_y;

	center_x = WINDOW_W / 8;
	center_y = WINDOW_H * 5 / 6;
	if (center_x < center_y)
		radius = center_x / 2;
	else
		radius = center_y / 2;
	int xi, yi;
	yi = -radius;
	while (yi <= radius)
	{
		xi = -radius;
		while (xi <= radius)
		{
			if (xi * xi + yi * yi <= radius * radius && xi * xi + yi * yi >= (radius * radius) - (10 * radius))
				put_pixel_to_img(&world->frame, center_x + xi, center_y + yi, BLACK);
			else if (xi * xi + yi * yi <= radius * radius)
			{
				if (!coord_in_map(world, (int)(world->pos.x + (xi / 10)), (int)(world->pos.y + (yi / 10))))
					put_pixel_to_img(&world->frame,center_x + xi, center_y + yi, NAVY);
				else if (world->map[(int)(world->pos.y + (yi / 10))][(int)(world->pos.x + (xi / 10))] == '1')
					put_pixel_to_img(&world->frame,center_x + xi, center_y + yi, VIOLET);
				else if (world->map[(int)(world->pos.y + (yi / 10))][(int)(world->pos.x + (xi / 10))] == ' ')
					put_pixel_to_img(&world->frame,center_x + xi, center_y + yi, NAVY);
				else if (world->map[(int)(world->pos.y + (yi / 10))][(int)(world->pos.x + (xi / 10))] == '2')
					put_pixel_to_img(&world->frame,center_x + xi, center_y + yi, GREY);
				else
					put_pixel_to_img(&world->frame, center_x + xi, center_y + yi, SILVER);
			}
			xi++;
		}
		yi++;
	}
	
	int	circle_player_radius = radius / 10;
	yi = -circle_player_radius;
	while (yi <= circle_player_radius)
	{
		xi = -circle_player_radius;
		while (xi <= circle_player_radius)
		{
			if (xi * xi + yi * yi <= circle_player_radius * circle_player_radius)
				put_pixel_to_img(&world->frame, center_x + xi, center_y + yi, 0x00000000);
			xi++;
		}
		yi++;
	}
}