/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:26:43 by wmari             #+#    #+#             */
/*   Updated: 2020/11/27 12:32:07 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*ptr;
	char	*s;
	size_t	copy;
	size_t	save;

	ptr = dst;
	save = ft_strlen(dst);
	copy = dstsize;
	s = (char *)src;
	while (copy-- > 0 && *ptr != '\0')
		ptr++;
	copy = dstsize - (ptr - dst);
	if (copy == 0)
		return ((ptr - dst) + ft_strlen(src));
	while (*s != '\0')
	{
		if (copy != 1)
		{
			*ptr++ = *s;
			copy--;
		}
		s++;
	}
	*ptr = '\0';
	return (save + ft_strlen(src));
}
