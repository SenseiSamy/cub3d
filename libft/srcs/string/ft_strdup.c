/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:53:37 by snaji             #+#    #+#             */
/*   Updated: 2023/05/18 22:05:45 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	len;

	if (!s1)
		return (NULL);
	len = (ft_strlen(s1));
	result = (char *)malloc((len + 1) * sizeof (*result));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, len);
	result[len] = '\0';
	return (result);
}
