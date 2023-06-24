/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:53:03 by snaji             #+#    #+#             */
/*   Updated: 2023/05/18 21:59:53 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*source = src;

	if (!dst && !src)
		return (NULL);
	dest = dst;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		++i;
	}
	return (dst);
}
