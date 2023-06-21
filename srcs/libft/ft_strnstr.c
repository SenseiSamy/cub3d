/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:56:23 by wmari             #+#    #+#             */
/*   Updated: 2021/10/28 12:35:18 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr_tofind;
	size_t	checked;
	int		i;

	if (*needle == '\0')
		return ((char *)haystack);
	ptr_tofind = (char *)needle;
	i = 0;
	while (haystack[i] != '\0' && (size_t)i < len)
	{
		if (haystack[i] == *ptr_tofind)
		{
			checked = 0;
			while (haystack[i + checked] == ptr_tofind[checked]
				&& ptr_tofind[checked] && (((size_t)i + checked)) < len)
				checked++;
			if (ptr_tofind[checked] == '\0')
			{
				ptr_tofind = (char *)(haystack + i);
				return (ptr_tofind);
			}
		}
		i++;
	}
	return (NULL);
}
