/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:45:42 by wmari             #+#    #+#             */
/*   Updated: 2023/07/18 14:29:49 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
			if (xi * xi + yi * yi <= radius * radius && xi * xi + yi * yi >= (radius * radius) - 250)
				put_pixel_to_img(&world->frame, center_x + xi, center_y + yi, BLACK);
			else if (xi * xi + yi * yi <= radius * radius)
			{
				put_pixel_to_img(&world->frame, center_x + xi, center_y + yi, GREY);
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