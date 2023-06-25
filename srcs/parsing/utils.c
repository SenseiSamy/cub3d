/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:54:10 by snaji             #+#    #+#             */
/*   Updated: 2023/06/25 19:50:29 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_sprite	open_sprite(t_world *world, char *path)
{
	t_sprite	sprite;

	sprite.x = 0;
	sprite.y = 0;
	sprite.sprite = NULL;
	sprite.sprite = mlx_xpm_file_to_image(world->mlx, path, &sprite.x,
		&sprite.y);
	return (sprite);
}

int	get_color(char *str)
{
	char	**split;
	int		color;

	split = ft_split(str, ',');
	if (split == NULL)
		return (-1);
	if (split[0] == NULL || split[1] == NULL || split[2] == NULL ||
		split[3] != NULL)
		return (-1);
	color = rgb(ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
	ft_freearray((void *)split);
	return (color);
}

int	rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}
