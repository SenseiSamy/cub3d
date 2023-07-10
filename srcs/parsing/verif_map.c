/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:21:57 by snaji             #+#    #+#             */
/*   Updated: 2023/07/10 17:18:03 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_start_pos(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
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

int	check_walls_rec(int y, int x, char **map)
{
	if (y < 0 || x < 0 || map[y] == NULL || map[y][x] == 0 || map[y][x] == ' ')
		return (1);
	if (map[y][x] == '1' || map[y][x] == '3')
		return (0);
	map[y][x] = '3';
	return (check_walls_rec(y + 1, x, map) + check_walls_rec(y - 1, x, map)
		+ check_walls_rec(y, x + 1, map) + check_walls_rec(y, x - 1, map));
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
			if (map[i][j] == '0' && check_walls_rec(i, j, map) >= 1)
				return (ft_dprintf(2, "Error\nMap not surrounded by walls\n"),
					EXIT_FAILURE);
			++j;
		}
		++i;
	}
	i = 0;
	while (map[i])
		ft_strrepl(map[i++], '3', '0');
	return (EXIT_SUCCESS);
}

int	verif_map(char **map)
{
	int		x;
	int		y;
	char	c;

	x = -1;
	y = -1;
	if (get_start_pos(map, &x, &y) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	c = map[x][y];
	if (check_walls(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map[x][y] = c;
	return (EXIT_SUCCESS);
}
