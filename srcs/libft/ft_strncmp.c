/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:16:47 by wmari             #+#    #+#             */
/*   Updated: 2021/10/28 12:34:05 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;

	ptrs1 = (unsigned char *)s1;
	ptrs2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	n = n - 1;
	while ((*ptrs1 == *ptrs2) && (n-- > 0) && *ptrs1 && *ptrs2)
	{
		ptrs1++;
		ptrs2++;
	}
	return (*ptrs1 - *ptrs2);
}
