/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:21:57 by snaji             #+#    #+#             */
/*   Updated: 2023/06/25 20:32:22 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_start_pos(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	*x = -1;
	*y = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				if (*x != -1 || *y != -1)
					return (ft_dprintf(2, "Error\nMultiple start position\n"),
						EXIT_FAILURE);
				*x = i;
				*y = j;
			}
			++j;
		}
		++i;
	}
	if (*x >= 0 && *y >= 0)
		return (EXIT_SUCCESS);
	return (ft_dprintf(2, "Error\nNo start position\n"), EXIT_FAILURE);
}

int	check_walls_rec(int x, int y, char **map)
{
	if (x < 0 || y < 0 || map[x][y] == 0 || map[x][y] == ' ')
		return (1);
	if (map[x][y] == '1' || map[x][y] == '3')
		return (0);
	map[x][y] = '3';
	return (check_walls_rec(x + 1, y, map) + check_walls_rec(x - 1, y, map)
		+ check_walls_rec(x, y + 1, map) + check_walls_rec(x, y - 1, map));
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && check_walls_rec(i, j, map) == 1)
				return (ft_dprintf(2, "Error\nMap not surrounded by walls\n"),
					EXIT_FAILURE);
			++j;
		}
		++i;
	}
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == '3')
				map[i][j - 1] = '0';
		++i;
	}
	return (EXIT_SUCCESS);
}

int	verif_map(char **map)
{
	int		x;
	int		y;
	char	c;

	if (get_start_pos(map, &x, &y) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	c = map[x][y];
	if (check_walls(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map[x][y] = c;
	return (EXIT_SUCCESS);
}