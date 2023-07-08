/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:21:01 by wmari             #+#    #+#             */
/*   Updated: 2023/07/08 18:17:19 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv, char **envp)
{
	t_world	world;

	(void)argc;
	(void)argv;
	(void)envp;
	ft_bzero(&world, sizeof (world));
	world.mlx = mlx_init();
	if (parse(&world, "maps/test.cub") == EXIT_FAILURE)
		return (1);
	free_world(&world);
	return (0);
}