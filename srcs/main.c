/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:21:01 by wmari             #+#    #+#             */
/*   Updated: 2023/07/13 15:02:51 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main_loop(t_world *world)
{
	if (!something_is_cooking(world))
	{
		mlx_clear_window(world->mlx, world->mlx_win);
		hook_key_press(world);
		raycast(world);
		world->refresh = 0;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_world	world;

	init_world(argc, argv, &world);
	raycast(&world);
	set_hooks(&world);
	mlx_loop_hook(world.mlx, main_loop, &world);
	mlx_loop(world.mlx);
	return (0);
}
