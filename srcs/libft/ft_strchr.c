/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:57:47 by wmari             #+#    #+#             */
/*   Updated: 2021/10/28 12:29:24 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	if (*ptr == (char)c)
		return (ptr);
	while (*ptr++)
	{
		if (*ptr == (char)c)
			return (ptr);
	}
	if ((char)c == '\0')
		return (ptr);
	return (NULL);
}
