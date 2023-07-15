/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:21:01 by wmari             #+#    #+#             */
/*   Updated: 2023/07/15 16:27:26 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_world	world;

	if (init_world(argc, argv, &world) == EXIT_FAILURE)
		exit_cub3d(&world);
	raycast(&world);
	set_hooks(&world);
	mlx_loop_hook(world.mlx, main_loop, &world);
	mlx_loop(world.mlx);
	return (0);
}
