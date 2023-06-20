/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:55:09 by wmari             #+#    #+#             */
/*   Updated: 2023/06/20 14:55:27 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_next_line(int fd, char **line)
{
	static char	*saved = NULL;
	int			nbread;

	nbread = 1;
	if (line == NULL || fd < 0 || fd > 256)
		return (-1);
	saved = fill_saved(fd, saved, &nbread, 100);
	if (!saved)
		return (-1);
	if (nbread > 0 || *saved != '\0')
		*line = new_line(saved);
	else
		*line = new_line("\0");
	saved = clean_saved(saved);
	if (!saved || !line)
		return (-1);
	if ((nbread == 0) && (*saved == '\0'))
	{
		if (saved)
			free(saved);
		saved = NULL;
		return (0);
	}
	return (1);
}

char	*fill_saved(int fd, char *saved, int *nbread, int buffer_size)
{
	char	*buf;

	while (check_saved(saved) && *nbread > 0)
	{
		buf = malloc(buffer_size + 1);
		if (!buf)
		{
			if (saved)
				free(saved);
			return (NULL);
		}
		*nbread = read(fd, buf, buffer_size);
		if (*nbread == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[*nbread] = '\0';
		saved = saved_append(saved, buf);
		free(buf);
	}
	return (saved);
}

int	check_saved(char *saved)
{
	int	i;

	if (!saved)
		return (1);
	i = 0;
	while (saved[i] != '\0' && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		return (0);
	return (1);
}

char	*new_line(char *saved)
{
	int		i;
	char	*newl;

	i = 0;
	while (saved[i] != '\0' && saved[i] != '\n')
		i++;
	newl = malloc(i + 1);
	if (!newl)
		return (NULL);
	i = 0;
	while (saved[i] != '\0' && saved[i] != '\n')
	{
		newl[i] = saved[i];
		i++;
	}
	newl[i] = '\0';
	return (newl);
}

char	*clean_saved(char *saved)
{
	int		i;
	int		j;
	int		k;
	char	*new_saved;

	i = 0;
	j = 0;
	while (saved[i] != '\0' && saved[i] != '\n')
		i++;
	while (saved[i + j] != '\0')
		j++;
	new_saved = malloc(j + 1);
	if (!new_saved)
	{
		free(saved);
		return (NULL);
	}
	k = 0;
	i++;
	while (k < j)
		new_saved[k++] = saved[i++];
	new_saved[k] = '\0';
	free(saved);
	return (new_saved);
}
