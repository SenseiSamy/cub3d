/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:45:32 by snaji             #+#    #+#             */
/*   Updated: 2023/08/11 16:08:00 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	tmp;

	i = 0;
	size = ft_strlen(str) - 1;
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - i];
		str[size - i] = tmp;
		++i;
	}
	return (str);
}
