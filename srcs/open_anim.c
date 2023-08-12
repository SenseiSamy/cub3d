/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:00:02 by snaji             #+#    #+#             */
/*   Updated: 2023/08/12 18:37:33 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*generate_path(char *file, int i)
{
	char	*begin;
	char	*nb;
	char	*res;
	int		len;

	len = ft_strlen(file);
	if (len < 10)
		return (NULL);
	begin = ft_calloc(len - 8, sizeof (char));
	if (begin == NULL)
		return (NULL);
	ft_strlcpy(begin, file, len - 8);
	nb = ft_itoa(i);
	if (nb == NULL)
		return (free(begin), NULL);
	res = ft_strmjoin(4, begin, "part", nb, ".xpm");
	free(begin);
	free(nb);
	return (res);
}

static int	nb_files_anim(char *path)
{
	int		i;
	int		fd;
	char	*file;

	i = 1;
	while (1)
	{
		file = generate_path(path, i);
		if (file == NULL)
			return (-1);
		fd = open(file, O_RDONLY);
		free(file);
		if (fd == -1)
			break;
		close(fd);
		++i;
	}
	return (i - 1);
}

static int	verif_anim(t_anim *anim)
{
	int	i;

	i = 0;
	while (i < anim->nb_frames)
	{
		if (anim->frames && anim->frames[i].img == NULL)
			return (1);
		++i;
	}
	return (0);
}

void	free_anim(t_world *world, t_anim *anim)
{
	int	n;

	n = 0;
	while (n < anim->nb_frames)
	{
		if (anim->frames[n].img)
			mlx_destroy_image(world->mlx, anim->frames[n].img);
		++n;
	}
	free(anim->frames);
	ft_bzero(anim, sizeof (t_anim));
}

t_anim	open_anim(t_world *world, char *path)
{
	t_anim	anim;
	int		i;
	char	*file;

	ft_bzero(&anim, sizeof (t_anim));
	if (path == NULL)
		return (anim);
	anim.nb_frames = nb_files_anim(path);
	if (anim.nb_frames <= 0)
		return (anim);
	anim.frames = ft_calloc(anim.nb_frames, sizeof (t_image));
	if (anim.frames == NULL)
		return (anim);
	i = 0;
	while (i < anim.nb_frames)
	{
		file = generate_path(path, i + 1);
		if (file == NULL)
			return (free(anim.frames), anim.frames = NULL, anim);
		anim.frames[i++] = open_sprite(world, file);
		free(file);
	}
	if (gettimeofday(&anim.frame_time, NULL) == -1 || verif_anim(&anim) == 1)
		return (free_anim(world, &anim), anim);
	return (anim);
}