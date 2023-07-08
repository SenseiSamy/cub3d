/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:54:16 by snaji             #+#    #+#             */
/*   Updated: 2023/07/08 18:07:59 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_map(char *line)
{
	int	i;

	i = 0;
	if (line[0] == 0)
		return (false);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i]
			!= 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (false);
		++i;
	}
	return (true);
}

char	**convert_map(t_list *map_list)
{
	char	**map;
	t_list	*ptr;
	int		i;

	map = ft_calloc(ft_lstsize(map_list) + 1, sizeof (char *));
	if (map == NULL)
		return (ft_dprintf(2, "Error\nMalloc failed\n"), NULL);
	ptr = map_list;
	i = 0;
	while (map_list)
	{
		map[i++] = (char *)map_list->content;
		ptr = map_list;
		map_list = map_list->next;
		free(ptr);
	}
	map[i] = NULL;
	return (map);
}

int	read_map(t_world *world, int fd, char *line)
{
	t_list	*map;
	t_list	*tmp;

	map = NULL;
	while (line != NULL)
	{
		ft_strrepl(line, '\n', '\0');
		if (is_map(line) == false)
			return (ft_dprintf(2, "Error\nInvalid character in map\n"),
				EXIT_FAILURE);
		tmp = ft_lstnew(line);
		if (tmp == NULL)
			return (ft_dprintf(2, "Error\nMalloc failed\n"), EXIT_FAILURE);
		ft_lstadd_back(&map, tmp);
		line = get_next_line(fd);
	}
	world->map = convert_map(map);
	if (world->map == NULL)
		return (EXIT_FAILURE);
	if (verif_map(world->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
