/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:34:54 by wmari             #+#    #+#             */
/*   Updated: 2021/10/28 12:44:43 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_string;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	new_string = (char *)malloc(len + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	if (ft_strlen(s) < start)
	{
		while (i <= len)
			new_string[i++] = '\0';
	}
	else
	{
		while (i <= len && s[start + i])
		{
			new_string[i] = s[start + i];
			i++;
		}
		while (i <= len)
			new_string[i++] = '\0';
	}
	return (new_string);
}
