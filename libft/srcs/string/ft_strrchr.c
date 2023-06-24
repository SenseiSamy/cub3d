/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:54:07 by snaji             #+#    #+#             */
/*   Updated: 2023/05/18 22:12:58 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			result = (char *)s;
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		result = (char *)s;
	return (result);
}
