/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:54:15 by snaji             #+#    #+#             */
/*   Updated: 2023/05/18 23:26:21 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	sub_size(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			size;

	size = 0;
	i = 0;
	while (s[i])
	{
		if (i >= start)
			++size;
		++i;
	}
	if (size < len)
		return (size);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	substr = (char *)malloc((sub_size(s, start, len) + 1) * sizeof (*substr));
	if (substr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			substr[j++] = s[i];
		++i;
	}
	substr[j] = '\0';
	return (substr);
}
