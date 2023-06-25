/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:23 by snaji             #+#    #+#             */
/*   Updated: 2023/06/25 19:58:59 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	open_file(const char *file_name)
{
	int		fd;
	char	*extension;

	if (file_name == NULL || file_name[0] == 0)
		return (ft_dprintf(2, "Error\nInvalid file input\n"), -1);
	extension = ft_strnstr(file_name, ".cub", ft_strlen(file_name));
	if (extension == NULL || extension[4] != 0)
		return (ft_dprintf(2, "Error\nInvalid file extension\n"), -1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Error\n%s\n", strerror(errno)), -1);
	return (fd);
}
