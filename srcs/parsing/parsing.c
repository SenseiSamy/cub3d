/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:02:06 by snaji             #+#    #+#             */
/*   Updated: 2023/06/25 19:57:36 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int parse(t_world *world, char *file_name)
{
	int fd;

	fd = open_file(file_name);
	if (fd == -1)
		return (EXIT_FAILURE);
	if (read_elem(world, fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}