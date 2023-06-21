/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:22:52 by wmari             #+#    #+#             */
/*   Updated: 2023/06/21 16:08:45 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mlx_not_working(char *env)
{
	if (!env)
	{
		printf("Error\nMLX not working\n");
		exit(0);
	}
}

int		path_invalid(char *path)
{
	int i;

	i = 0;
	while (path[i])
		i++;
	if (ft_strncmp(&path[i - 4], ".cub", 5) || (!path[i - 5] || path[i - 5] == "/"))
		return (1);
	return (0);
}

int		init_world(char **argv, char **envp)
{
	mlx_not_working(envp[0]);
	if (path_invalid(argv[1]))
		
}

