/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:22:52 by wmari             #+#    #+#             */
/*   Updated: 2023/07/10 16:45:51 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_mlx(t_world *world)
{
	int	x;
	int	y;

	world->mlx = mlx_init();
	if (world->mlx == NULL)
		return (EXIT_FAILURE);
	mlx_get_screen_size(world->mlx, &x, &y);
	world->mlx_win = mlx_new_window(world->mlx, x, y, "Cub3D");
	if (world->mlx_win == NULL)
		return (EXIT_FAILURE);
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
	return (EXIT_SUCCESS);
}
