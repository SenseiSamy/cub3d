/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:47:45 by wmari             #+#    #+#             */
/*   Updated: 2023/06/20 14:55:11 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*saved_append(char *saved, char *buf)
{
	char	*new_saved;

	new_saved = create_new_saved(saved, buf);
	if (!new_saved)
	{
		if (saved)
			free(saved);
		return (NULL);
	}
	if (saved)
	{
		fill_with_save(new_saved, saved, buf);
		free(saved);
	}
	else
		fill_with_buf(new_saved, buf);
	return (new_saved);
}

void	fill_with_save(char *nsaved, char *saved, char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (saved[i] != '\0')
	{
		nsaved[i] = saved[i];
		i++;
	}
	while (buf[j] != '\0')
		nsaved[i++] = buf[j++];
	nsaved[i] = '\0';
}

void	fill_with_buf(char *nsaved, char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
	{
		nsaved[i] = buf[i];
		i++;
	}
	nsaved[i] = '\0';
}

size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s[lenght] != '\0')
		lenght++;
	return (lenght);
}

char	*create_new_saved(char *saved, char *buf)
{
	char	*new_saved;

	if (saved)
	{
		new_saved = malloc(ft_strlen(saved) + ft_strlen(buf) + 1);
		if (!new_saved)
		{
			free(saved);
			return (NULL);
		}
	}
	else
	{
		new_saved = malloc(ft_strlen(buf) + 1);
		if (!new_saved)
			return (NULL);
	}
	return (new_saved);
}
