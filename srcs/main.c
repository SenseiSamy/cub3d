/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:21:01 by wmari             #+#    #+#             */
/*   Updated: 2023/07/20 13:20:15 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_world	world;

	if (init_world(argc, argv, &world) == EXIT_FAILURE)
		exit_cub3d(&world);
	raycast(&world);
	draw_minimap(&world);
	set_hooks(&world);
	mlx_loop_hook(world.mlx, main_loop, &world);
	mlx_loop(world.mlx);
	return (0);
}
