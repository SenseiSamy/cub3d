/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:18:07 by snaji             #+#    #+#             */
/*   Updated: 2023/07/18 19:14:40 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_image	open_sprite(t_world *world, char *path)
{
	t_image	sprite;

	ft_bzero(&sprite, sizeof (sprite));
	sprite.img = mlx_xpm_file_to_image(world->mlx, path, &sprite.w,
			&sprite.h);
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel,
			&sprite.line_length, &sprite.endian);
	return (sprite);
}

void	put_pixel_to_img(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_from_img(t_image *img, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return (0);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	clear_image(t_world *world)
{
	int	i;
	int	j;

	i = 0;
	while (i < world->frame.h)
	{
		j = 0;
		while (j < world->frame.w)
		{
			if (i < world->frame.h / 2)
				put_pixel_to_img(&world->frame, j, i, world->ceiling_color);
			else
				put_pixel_to_img(&world->frame, j, i, world->floor_color);
			++j;
		}
		++i;
	}
}
