/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:10:12 by wmari             #+#    #+#             */
/*   Updated: 2021/10/28 12:35:31 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	char	*ptr;

	ptr = (char *)s;
	ret = NULL;
	while (*ptr)
	{
		if (*ptr == (char)c)
			ret = ptr;
		ptr++;
	}
	if (*ptr == (char)c)
		ret = ptr;
	return (ret);
}
