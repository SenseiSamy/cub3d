/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:19:09 by wmari             #+#    #+#             */
/*   Updated: 2020/11/30 12:50:30 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptrdst;
	char	*ptrsrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		ptrdst = (char *)(dst + len - 1);
		ptrsrc = (char *)(src + len - 1);
		while (len-- > 0)
			*ptrdst-- = *ptrsrc--;
	}
	else
	{
		ptrdst = (char *)dst;
		ptrsrc = (char *)src;
		while (len-- > 0)
			*ptrdst++ = *ptrsrc++;
	}
	return (dst);
}
