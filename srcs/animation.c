/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:14:07 by snaji             #+#    #+#             */
/*   Updated: 2023/08/11 20:16:37 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_anim(char *path)
{
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len > 9 && ft_strncmp(&path[len - 9], "part1.xpm", 10) == 0)
		return (0);
	return (1);
}

static t_image	open_sprite(t_world *world, char *path)
{
	t_image	sprite;

	ft_bzero(&sprite, sizeof (sprite));
	sprite.img = mlx_xpm_file_to_image(world->mlx, path, &sprite.w,
			&sprite.h);
	if (sprite.img != NULL)
		sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel,
			&sprite.line_length, &sprite.endian);
	return (sprite);
}

static t_anim	*open_anim(t_world *world, char *path)
{
	t_anim	anim;
	int		i;
	int		fd;
	char	*file;
	char	*nb;

	path = ft_strdup(path);
	if (path == NULL)
		return (NULL);
	path[ft_strlen(path) - 9] = '\0';
	i = 1;
	file = ft_strmjoin(3, path, )
	while 
	
}

t_texture	open_texture(t_world *world, char *path)
{
	t_texture	texture;

	ft_bzero(&texture, sizeof (texture));
	if (path && is_anim(path))
	{
		texture.type = 1;
		texture.anim = open_anim(world, path);
	}
	else
	{
		texture.type = 0;
		texture.image = open_sprite(world, path);
	}
	return (texture);
}