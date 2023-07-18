/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_el.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:26 by snaji             #+#    #+#             */
/*   Updated: 2023/07/18 19:04:34 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_elem(char *line)
{
	const char	*ids[] = {"NO", "SO", "WE", "EA", "DO", "F", "C", NULL};
	int			i;

	i = 0;
	while (*line == ' ')
		++line;
	while (ids[i])
	{
		if (ft_strncmp(line, ids[i], ft_strlen(ids[i])) == 0)
			return (true);
		++i;
	}
	return (false);
}

int	set_elem(t_world *world, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split == NULL)
		return (ft_dprintf(2, "Error\nMalloc failed\n"), EXIT_FAILURE);
	if (split[0] == NULL || split[1] == NULL || split[2] != NULL)
		return (EXIT_FAILURE);
	if (ft_strncmp(split[0], "NO", 3) == 0)
		world->northwall = open_sprite(world, split[1]);
	else if (ft_strncmp(split[0], "SO", 3) == 0)
		world->southwall = open_sprite(world, split[1]);
	else if (ft_strncmp(split[0], "WE", 3) == 0)
		world->westwall = open_sprite(world, split[1]);
	else if (ft_strncmp(split[0], "EA", 3) == 0)
		world->eastwall = open_sprite(world, split[1]);
	else if (ft_strncmp(split[0], "DO", 3) == 0)
		world->door = open_sprite(world, split[1]);
	else if (ft_strncmp(split[0], "F", 2) == 0)
		world->floor_color = get_color(split[1]);
	else if (ft_strncmp(split[0], "C", 2) == 0)
		world->ceiling_color = get_color(split[1]);
	else
		return (ft_dprintf(2, "Error\nFailed to get element in this line: "
				"'%s'\n", line), ft_freearray((void **)split), EXIT_FAILURE);
	return (ft_freearray((void **)split), EXIT_SUCCESS);
}

int	verif_elem(t_world *world)
{
	if (world->northwall.img == NULL)
		ft_dprintf(2, "Error\nFailed to open north wall texture\n");
	else if (world->southwall.img == NULL)
		ft_dprintf(2, "Error\nFailed to open south wall texture\n");
	else if (world->westwall.img == NULL)
		ft_dprintf(2, "Error\nFailed to open west wall texture\n");
	else if (world->eastwall.img == NULL)
		ft_dprintf(2, "Error\nFailed to open east wall texture\n");
	else if (world->floor_color == -1)
		ft_dprintf(2, "Error\nFailed to get the floor color\n");
	else if (world->ceiling_color == -1)
		ft_dprintf(2, "Error\nFailed to get the ceiling color\n");
	else
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	read_elem(t_world *world, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_strrepl(line, '\n', '\0');
		if (is_elem(line))
		{
			if (set_elem(world, line) == EXIT_FAILURE)
				return (free(line), EXIT_FAILURE);
		}
		else if (is_map(line))
			break ;
		else if (line[0] != 0)
			return (ft_dprintf(2, "Error\nInvalid line : %s\n", line),
				free(line), EXIT_FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	if (verif_elem(world) == EXIT_FAILURE)
		return (free_world(world), free(line), EXIT_FAILURE);
	if (read_map(world, fd, line) == EXIT_FAILURE)
		return (free_world(world), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
