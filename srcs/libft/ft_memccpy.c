/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:59:27 by wmari             #+#    #+#             */
/*   Updated: 2021/10/28 12:27:48 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;

	ptrdst = (unsigned char *)dst;
	ptrsrc = (unsigned char *)src;
	while (n-- > 0)
	{
		if (*ptrsrc == (unsigned char)c)
		{
			*ptrdst = *ptrsrc;
			ptrdst++;
			return (ptrdst);
		}
		else
		{
			*ptrdst++ = *ptrsrc++;
		}
	}
	return (NULL);
}
