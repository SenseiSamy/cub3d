/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:22:52 by wmari             #+#    #+#             */
/*   Updated: 2023/07/11 16:19:11 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	clear_image(world);
	set_hooks(world);
	return (EXIT_SUCCESS);
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
	world->pos.x = 10.0;
	world->pos.y = 10.0;
	world->dir.x = -1;
	world->dir.y = 0;
	world->plane.x = 0;
	world->plane.y = 0.66;
	return (EXIT_SUCCESS);
}
