/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:02:06 by snaji             #+#    #+#             */
/*   Updated: 2023/08/23 12:22:31 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parse(t_world *world, char *file_name)
{
	int	fd;

	fd = open_file(file_name);
	if (fd == -1)
		return (EXIT_FAILURE);
	world->ceiling_color = -1;
	world->floor_color = -1;
	if (read_elem(world, fd) == EXIT_FAILURE)
	{
		get_next_line(-1);
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
