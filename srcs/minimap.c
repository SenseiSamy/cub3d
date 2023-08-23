/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:45:42 by wmari             #+#    #+#             */
/*   Updated: 2023/08/23 11:05:04 by wmari            ###   ########.fr       */
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
	int	xi;
	int	yi;
	int	leny;
	int	lenx;

	leny = world->minimap.radius * MINIMAP_ZOOM ;
	lenx = world->minimap.radius * MINIMAP_ZOOM * 1.3;
	yi = -leny;
	while (yi <= leny)
	{
		xi = lenx - abs(yi);
		while (xi > 0)
		{
			put_pixel_to_img(&world->frame, world->minimap.center_x + yi,
				world->minimap.center_y - xi + lenx, BLACK);
			xi--;
		}
		yi++;
	}
}

static void	put_pix_map(t_world *world, int xi, int yi, int color)
{
	put_pixel_to_img(&world->frame, world->minimap.center_x + xi,
		world->minimap.center_y + yi, color);
}

void	color_circle(t_world *world, int xi, int yi)
{
	int	rotated_x;
	int	rotated_y;

	rotated_x = xi;
	rotated_y = yi;
	rotate_point(world, &rotated_x, &rotated_y);
	if (!coord_in_map(world, (int)(world->pos.x + (rotated_x * MINIMAP_ZOOM)),
		(int)(world->pos.y + (rotated_y * MINIMAP_ZOOM))))
		put_pix_map(world, xi, yi, NAVY);
	else if (world->map[(int)(world->pos.y + (rotated_y * MINIMAP_ZOOM))]
		[(int)(world->pos.x + (rotated_x * MINIMAP_ZOOM))] == '1')
		put_pix_map(world, xi, yi, VIOLET);
	else if (world->map[(int)(world->pos.y + (rotated_y * MINIMAP_ZOOM))]
		[(int)(world->pos.x + (rotated_x * MINIMAP_ZOOM))] == ' ')
		put_pix_map(world, xi, yi, NAVY);
	else if (world->map[(int)(world->pos.y + (rotated_y * MINIMAP_ZOOM))]
		[(int)(world->pos.x + (rotated_x * MINIMAP_ZOOM))] == '2')
		put_pix_map(world, xi, yi, GREY);
	else if (world->map[(int)(world->pos.y + (rotated_y * MINIMAP_ZOOM))]
		[(int)(world->pos.x + (rotated_x * MINIMAP_ZOOM))] == '3')
		put_pix_map(world, xi, yi, GREY + 0x00151515);
	else
		put_pix_map(world, xi, yi, SILVER);
}

void	draw_minimap(t_world *world)
{
	draw_circle(world);
	draw_player(world);
}
