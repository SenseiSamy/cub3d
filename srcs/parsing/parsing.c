/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:26 by snaji             #+#    #+#             */
/*   Updated: 2023/06/24 17:42:01 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*get_id(char *line)
{
	const char	*ids[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int			i;

	i = 0;
	while (ids[i])
	{
		if (ft_strnstr(line, ids[i], ft_strlen(ids[i])) != NULL)
			return (ids[i]);
		++i;
	}
	return (NULL);
}

int	set_elem(char *line, char *id)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split == NULL)
		return (ft_dprintf(2, "Error\nMalloc failed\n"), EXIT_FAILURE);
	if (split[0] == NULL || split[1] == NULL || split[2] != NULL)

}

int	read_file(t_world *world, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*line == 0)
			continue ;
		if (get_id())

	}
}

int	parse_map(t_world *world, char *file_name)
{
	int	fd;

	fd = open_file(file_name);
	if (fd == -1)
		return (EXIT_FAILURE);
	
}