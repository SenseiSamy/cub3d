/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:21:01 by wmari             #+#    #+#             */
/*   Updated: 2023/08/21 15:07:34 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_world	world;

	if (init_world(argc, argv, &world) == EXIT_FAILURE)
		exit_cub3d(&world);
	mlx_mouse_hide(world.mlx, world.mlx_win);
	raycast(&world);
	draw_minimap(&world);
	mlx_mouse_move(world.mlx, world.mlx_win, WINDOW_W * 0.5, WINDOW_H * 0.5);
	set_hooks(&world);
	mlx_loop_hook(world.mlx, main_loop, &world);
	mlx_loop(world.mlx);
	return (0);
}
