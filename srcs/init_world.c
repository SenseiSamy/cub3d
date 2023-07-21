/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:22:52 by wmari             #+#    #+#             */
/*   Updated: 2023/07/21 16:17:14 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_keys(t_world *world)
{
	world->keys.down = 0;
	world->keys.up = 0;
	world->keys.escape = 0;
	world->keys.larrow = 0;
	world->keys.left = 0;
	world->keys.rarrow = 0;
	world->keys.right = 0;
	world->mouse.x = WINDOW_W / 2;
	world->mouse.y = WINDOW_H / 2;
	world->focus = 1;
}

static int	init_mlx(t_world *world)
{
	world->mlx = mlx_init();
	if (world->mlx == NULL)
		return (EXIT_FAILURE);
	world->mlx_win = mlx_new_window(world->mlx, WINDOW_W, WINDOW_H, "Cub3D");
	if (world->mlx_win == NULL)
		return (EXIT_FAILURE);
	world->frame.img = mlx_new_image(world->mlx, WINDOW_W, WINDOW_H);
	world->frame.w = WINDOW_W;
	world->frame.h = WINDOW_H;
	world->frame.addr = mlx_get_data_addr(world->frame.img,
			&world->frame.bits_per_pixel, &world->frame.line_length,
			&world->frame.endian);
	mlx_do_key_autorepeatoff(world->mlx);
	clear_image(world);
	return (EXIT_SUCCESS);
}

static void	init_player(t_world *world)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	get_start_pos(world->map, &x, &y);
	world->pos.y = (double)x + 0.5;
	world->pos.x = (double)y + 0.5;
	world->dir.x = -1.0;
	world->dir.y = 0.0;
	world->plane.x = 0.0;
	world->plane.y = 0.80;
	if (world->map[x][y] == 'N')
		rotate_cam(world, M_PI / 2);
	else if (world->map[x][y] == 'S')
		rotate_cam(world, -M_PI / 2);
	else if (world->map[x][y] == 'W')
		rotate_cam(world, M_PI);
}

static void	init_minimap(t_world *world)
{
	world->minimap.center_x = WINDOW_W / 8;
	world->minimap.center_y = WINDOW_H * 5 / 6;
	if (world->minimap.center_x < world->minimap.center_y)
		world->minimap.radius = world->minimap.center_x / 2;
	else
		world->minimap.radius = world->minimap.center_y / 2;
}

int	init_world(int argc, char **argv, t_world *world)
{
	ft_bzero(world, sizeof (*world));
	if (argc < 2)
		return (ft_dprintf(2, "Error\nNot enough argument\n"), EXIT_FAILURE);
	if (argc > 2)
		return (ft_dprintf(2, "Error\nToo many arguments\n"), EXIT_FAILURE);
	if (init_mlx(world) == EXIT_FAILURE)
		return (ft_dprintf(2, "Error\nMLX error\n"), EXIT_FAILURE);
	if (parse(world, argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_player(world);
	init_keys(world);
	init_minimap(world);
	return (EXIT_SUCCESS);
}
