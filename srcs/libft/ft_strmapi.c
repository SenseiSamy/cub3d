/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:17:41 by wmari             #+#    #+#             */
/*   Updated: 2021/10/28 12:33:03 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapped;
	char			*ptr;
	unsigned int	i;

	if (s == NULL || (f) == NULL)
		return (NULL);
	mapped = (char *)malloc(ft_strlen(s) + 1);
	if (!mapped)
		return (NULL);
	ptr = (char *)s;
	i = 0;
	while (*ptr != '\0')
	{
		mapped[i] = (*f)(i, *ptr);
		i++;
		ptr++;
	}
	mapped[i] = '\0';
	return (mapped);
}
