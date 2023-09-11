/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:54:10 by snaji             #+#    #+#             */
/*   Updated: 2023/08/23 11:41:38 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_color(char *str)
{
	char	**split;
	int		color;

	split = ft_split(str, ',');
	if (split == NULL)
		return (-1);
	if (split[0] == NULL || split[1] == NULL || split[2] == NULL
		|| split[3] != NULL)
		return (ft_freearray((void **)split), -1);
	if (ft_atoi(split[0]) > 255 || ft_atoi(split[1]) > 255
		|| ft_atoi(split[2]) > 255)
		return (ft_freearray((void **)split), -1);
	color = rgb(ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
	ft_freearray((void **)split);
	return (color);
}

int	rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

bool	map_has_door(t_world *world)
{
	int	i;
	int	j;

	i = 0;
	while (world->map[i])
	{
		j = 0;
		while (world->map[i][j])
			if (world->map[i][j++] == '2')
				return (true);
		++i;
	}
	return (false);
}
