/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:21:01 by wmari             #+#    #+#             */
/*   Updated: 2023/06/25 20:21:26 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv, char **envp)
{
	t_world	world;
	world.mlx = mlx_init();

	(void)argc;
	(void)argv;
	(void)envp;
	parse(&world, "maps/map1.cub");
	return (0);
}